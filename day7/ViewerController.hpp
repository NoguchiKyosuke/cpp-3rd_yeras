#ifndef VIEWER_CONTROLLER_HPP
#define VIEWER_CONTROLLER_HPP

#include <gtk/gtk.h>

// GTKアプリケーションのイベントハンドラ（動的ライブラリで提供）
void on_app_startup(GApplication* app, gpointer user_data);
void on_app_activate(GApplication* app, gpointer user_data);

#endif // VIEWER_CONTROLLER_HPP