#ifndef VIEWER_CONTROLLER_HPP
#define VIEWER_CONTROLLER_HPP

#include <gtk/gtk.h>

// メイン側から呼び出すGUI制御用のコールバック関数
void on_app_startup(GApplication* app, gpointer user_data);
void on_app_activate(GApplication* app, gpointer user_data);

#endif // VIEWER_CONTROLLER_HPP