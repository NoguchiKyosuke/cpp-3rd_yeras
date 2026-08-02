#include <gdk-pixbuf/gdk-pixbuf.h>
#include <algorithm>

// dlsymから名前で探せるようにC言語のシンボル名で公開する
extern "C" {
    void apply_mosaic_filter(GdkPixbuf* pixbuf, int start_x, int start_y, int end_x, int end_y, int block_size) {
        if (!pixbuf) return;

        int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
        int n_channels = gdk_pixbuf_get_n_channels(pixbuf);
        guchar* pixels = gdk_pixbuf_get_pixels(pixbuf);

        // 指定されたブロックサイズごとに区切って処理
        for (int by = start_y; by < end_y; by += block_size) {
            for (int bx = start_x; bx < end_x; bx += block_size) {
                // 画像の端でブロックがはみ出ないように調整
                int bw = std::min(block_size, end_x - bx);
                int bh = std::min(block_size, end_y - by);
                int count = bw * bh;

                // ブロック内のRGB合計値を計算
                long sum_r = 0, sum_g = 0, sum_b = 0;
                for (int y = 0; y < bh; y++) {
                    for (int x = 0; x < bw; x++) {
                        guchar* p = pixels + (by + y) * rowstride + (bx + x) * n_channels;
                        sum_r += p[0];
                        sum_g += p[1];
                        sum_b += p[2];
                    }
                }

                // 色の平均値を出す
                guchar avg_r = sum_r / count;
                guchar avg_g = sum_g / count;
                guchar avg_b = sum_b / count;

                // ブロック内の全ピクセルを平均色で塗りつぶす
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
    }
}