#include "ImageEditor.hpp"
#include <iostream>
#include <algorithm>
#include <dlfcn.h>

ImageEditor::ImageEditor(GtkImage* widget)
    : image_widget(widget), current_pixbuf(nullptr), block_size(10) {}

ImageEditor::~ImageEditor() {
    if (current_pixbuf) {
        g_object_unref(current_pixbuf);
    }
}

void ImageEditor::load_file(const char* filename) {
    if (!filename) return;

    // 古い画像が残っていたら解放する
    if (current_pixbuf) {
        g_object_unref(current_pixbuf);
        current_pixbuf = nullptr;
    }

    current_pixbuf = gdk_pixbuf_new_from_file(filename, NULL);
    if (!current_pixbuf) return;

    int w = gdk_pixbuf_get_width(current_pixbuf);
    int h = gdk_pixbuf_get_height(current_pixbuf);

    // ウィジェットに画像をセットしてサイズを合わせる
    gtk_image_set_from_pixbuf(image_widget, current_pixbuf);
    gtk_widget_set_size_request(GTK_WIDGET(image_widget), w, h);
}

void ImageEditor::apply_plugin_filter(const char* plugin_path, int start_x, int start_y, int end_x, int end_y) {
    if (!current_pixbuf) return;

    // 座標が画像の外にはみ出ないよう範囲内に収める
    int w = gdk_pixbuf_get_width(current_pixbuf);
    int h = gdk_pixbuf_get_height(current_pixbuf);
    start_x = std::max(0, std::min(start_x, w));
    start_y = std::max(0, std::min(start_y, h));
    end_x   = std::max(0, std::min(end_x, w));
    end_y   = std::max(0, std::min(end_y, h));

    // プラグイン(.so)の読み込み
    void* handle = dlopen(plugin_path, RTLD_LAZY);
    if (!handle) {
        std::cerr << "プラグインのロード失敗: " << dlerror() << std::endl;
        return;
    }

    // シンボル名から関数ポインタを取得
    using FilterFunc = void (*)(GdkPixbuf*, int, int, int, int, int);
    FilterFunc filter_func = reinterpret_cast<FilterFunc>(dlsym(handle, "apply_mosaic_filter"));
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "関数シンボルの取得失敗: " << dlsym_error << std::endl;
        dlclose(handle);
        return;
    }

    // 加工を実行してからライブラリを閉じる
    filter_func(current_pixbuf, start_x, start_y, end_x, end_y, block_size);
    dlclose(handle);

    // 変更されたピクセルを画面に再反映
    gtk_image_set_from_pixbuf(image_widget, current_pixbuf);
}

void ImageEditor::clear() {
    if (current_pixbuf) {
        g_object_unref(current_pixbuf);
        current_pixbuf = nullptr;
    }
    gtk_image_clear(image_widget);
}