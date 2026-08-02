#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <algorithm>
#include <iostream>

class ImageEditor {
private:
    GtkImage* image_widget;
    GdkPixbuf* current_pixbuf;
    int block_size;

public:
    // コンストラクタ（初期化）
    ImageEditor(GtkImage* widget) 
        : image_widget(widget), current_pixbuf(nullptr), block_size(10) {}

    // デストラクタ（メモリ解放）
    ~ImageEditor() {
        if (current_pixbuf) {
            g_object_unref(current_pixbuf);
        }
    }

    // 画像ファイルの読み込み
    void load_file(const char* filename) {
        if (!filename) return;
        
        if (current_pixbuf) {
            g_object_unref(current_pixbuf);
        }

        current_pixbuf = gdk_pixbuf_new_from_file(filename, NULL);
        if (!current_pixbuf) return;

        int w = gdk_pixbuf_get_width(current_pixbuf);
        int h = gdk_pixbuf_get_height(current_pixbuf);

        gtk_image_set_from_pixbuf(image_widget, current_pixbuf);
        gtk_widget_set_size_request(GTK_WIDGET(image_widget), w, h);
    }

    // モザイク加工の実行
    void apply_mosaic(int start_x, int start_y, int end_x, int end_y) {
        if (!current_pixbuf) return;

        int w = gdk_pixbuf_get_width(current_pixbuf);
        int h = gdk_pixbuf_get_height(current_pixbuf);
        int rowstride = gdk_pixbuf_get_rowstride(current_pixbuf);
        int n_channels = gdk_pixbuf_get_n_channels(current_pixbuf);
        guchar* pixels = gdk_pixbuf_get_pixels(current_pixbuf);

        start_x = std::max(0, start_x);
        start_y = std::max(0, start_y);
        end_x = std::min(w, end_x);
        end_y = std::min(h, end_y);

        for (int by = start_y; by < end_y; by += block_size) {
            for (int bx = start_x; bx < end_x; bx += block_size) {
                int bw = std::min(block_size, end_x - bx);
                int bh = std::min(block_size, end_y - by);
                int count = bw * bh;

                long sum_r = 0, sum_g = 0, sum_b = 0;
                for (int y = 0; y < bh; y++) {
                    for (int x = 0; x < bw; x++) {
                        guchar* p = pixels + (by + y) * rowstride + (bx + x) * n_channels;
                        sum_r += p[0];
                        sum_g += p[1];
                        sum_b += p[2];
                    }
                }
                guchar avg_r = sum_r / count;
                guchar avg_g = sum_g / count;
                guchar avg_b = sum_b / count;

                for (int y = 0; y < bh; y++) {
                    for (int x = 0; x < bw; x++) {
                        guchar* p = pixels + (by + y) * rowstride + (bx + x) * n_channels;
                        p[0] = avg_r;
                        p[1] = avg_g;
                        p[2] = avg_b;
                    }
                }
            }
        }

        // 変更を画面に反映
        gtk_image_set_from_pixbuf(image_widget, current_pixbuf);
    }

    // クリア機能
    void clear() {
        if (current_pixbuf) {
            g_object_unref(current_pixbuf);
            current_pixbuf = nullptr;
        }
        gtk_image_clear(image_widget);
    }
};