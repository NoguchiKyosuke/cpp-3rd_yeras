#include <gdk-pixbuf/gdk-pixbuf.h>
#include <algorithm>

extern "C" {
    void apply_mosaic_filter(GdkPixbuf* pixbuf, int start_x, int start_y, int end_x, int end_y, int block_size) {
        if (!pixbuf) return;

        int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
        int n_channels = gdk_pixbuf_get_n_channels(pixbuf);
        guchar* pixels = gdk_pixbuf_get_pixels(pixbuf);

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
    }
}