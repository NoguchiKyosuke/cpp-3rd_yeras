#ifndef IMAGE_UTILS_HPP
#define IMAGE_UTILS_HPP

#include <gdk-pixbuf/gdk-pixbuf.h>

// 座標が画像の範囲内に収まるように補正するユーティリティ関数
void clip_coordinates(GdkPixbuf* pixbuf, int& start_x, int& start_y, int& end_x, int& end_y);

#endif // IMAGE_UTILS_HPP