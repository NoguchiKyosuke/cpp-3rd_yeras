#include "image_utils.hpp"
#include <algorithm>

void clip_coordinates(GdkPixbuf* pixbuf, int& start_x, int& start_y, int& end_x, int& end_y) {
    if (!pixbuf) return;

    int w = gdk_pixbuf_get_width(pixbuf);
    int h = gdk_pixbuf_get_height(pixbuf);

    start_x = std::max(0, std::min(start_x, w));
    start_y = std::max(0, std::min(start_y, h));
    end_x   = std::max(0, std::min(end_x, w));
    end_y   = std::max(0, std::min(end_y, h));
}