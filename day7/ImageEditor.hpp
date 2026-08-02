#ifndef IMAGE_EDITOR_HPP
#define IMAGE_EDITOR_HPP

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

// 画像データと表示用ウィジェットをまとめて管理するクラス
class ImageEditor {
private:
    GtkImage* image_widget;
    GdkPixbuf* current_pixbuf; // 編集中の画像データ
    int block_size;            // モザイクの目の粗さ

public:
    explicit ImageEditor(GtkImage* widget);
    ~ImageEditor();

    void load_file(const char* filename);
    void apply_plugin_filter(const char* plugin_path, int start_x, int start_y, int end_x, int end_y);
    void clear();
};

#endif // IMAGE_EDITOR_HPP