#include <gtk/gtk.h>
#include "ViewerController.hpp" // 動的ライブラリが提供するコントローラー

int main(int argc, char** argv) {
    // GTKアプリケーションの生成
    GtkApplication* app = gtk_application_new("org.gtk.tutorial",
                                                G_APPLICATION_FLAGS_NONE);

    // 動的ライブラリ (libviewer_controller.so) 内のハンドラを紐付け
    g_signal_connect(G_OBJECT(app), "startup",  G_CALLBACK(on_app_startup),  NULL);
    g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(on_app_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    
    g_object_unref(app);
    return status;
}