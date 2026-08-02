#ifndef MOSAIC_FILTER_HPP
#define MOSAIC_FILTER_HPP

#include <gdk-pixbuf/gdk-pixbuf.h>

// モザイク処理を行う外部関数の宣言
void apply_mosaic_filter(GdkPixbuf* pixbuf, int start_x, int start_y, int end_x, int end_y, int block_size);

#endif // MOSAIC_FILTER_HPP