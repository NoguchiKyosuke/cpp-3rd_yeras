#include "ViewerController.hpp"
#include "ImageEditor.hpp"
#include <iostream>
#include <algorithm>

// --- マウスドラッグ・イベントハンドラ ---
static void
on_drag_end(GtkGestureDrag* gesture, double offset_x, double offset_y, gpointer user_data) {
    ImageEditor* editor = static_cast<ImageEditor*>(user_data);
    double start_x, start_y;

    if (gtk_gesture_drag_get_start_point(gesture, &start_x, &start_y)) {
        double end_x = start_x + offset_x;
        double end_y = start_y + offset_y;

        int x1 = static_cast<int>(std::min(start_x, end_x));
        int y1 = static_cast<int>(std::min(start_y, end_y));
        int x2 = static_cast<int>(std::max(start_x, end_x));
        int y2 = static_cast<int>(std::max(start_y, end_y));

        std::cout << "選択した領域: (" << x1 << ", " << y1 << ") - (" 
                  << x2 << ", " << y2 << ")" << std::endl;

        // プラグインを呼び出して部分モザイクを実行
        editor->apply_plugin_filter("./mosaic_plugin.so", x1, y1, x2, y2);
    }
}

// --- メニュー機能：画像のを開く ---
static void
open_image(GObject* object, GAsyncResult* result, gpointer user_data) {
    GFile* file = gtk_file_dialog_open_finish(GTK_FILE_DIALOG(object), result, NULL);
    if (file) {
        ImageEditor* editor = static_cast<ImageEditor*>(g_object_get_data(G_OBJECT(user_data), "editor"));
        char* filename = g_file_get_path(file);
        editor->load_file(filename);
        g_free(filename);
    }
}

static void
on_menu_open(GSimpleAction* action, GVariant* parameter, gpointer user_data) {
    GtkFileDialog* dialog = gtk_file_dialog_new();
    gtk_file_dialog_set_title(dialog, "Open an image");
    GFile* dirname = g_file_new_for_path(g_path_get_dirname(__FILE__));
    gtk_file_dialog_set_initial_folder(dialog, dirname);
    gtk_file_dialog_open(dialog,
                          gtk_application_get_active_window(GTK_APPLICATION(user_data)),
                          NULL, open_image, user_data);
}

// --- メニュー機能：クリア ---
static void
on_menu_clear(GSimpleAction* action, GVariant* parameter, gpointer user_data) {
    ImageEditor* editor = static_cast<ImageEditor*>(g_object_get_data(G_OBJECT(user_data), "editor"));
    if (editor) {
        editor->clear();
    }
}

// --- メニュー機能：終了 ---
static void
on_menu_quit(GSimpleAction* action, GVariant* parameter, gpointer user_data) {
    g_application_quit(G_APPLICATION(user_data));
}

static GActionEntry app_entries[] = {
    {"menu_open", on_menu_open,  NULL, NULL, NULL},
    {"clear",     on_menu_clear, NULL, NULL, NULL},
    {"menu_quit", on_menu_quit,  NULL, NULL, NULL}
};

// --- ウィンドウの構築 ---
static GtkWidget*
image_window_new(GApplication* app) {
    GtkWidget* window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "Image viewer");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget* scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_vexpand(scrolled_window, TRUE);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                    GTK_POLICY_AUTOMATIC,
                                    GTK_POLICY_AUTOMATIC);
    gtk_window_set_child(GTK_WINDOW(window), scrolled_window);

    GtkWidget* image = gtk_image_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), image);
    gtk_widget_set_hexpand(image, FALSE);
    gtk_widget_set_vexpand(image, FALSE);
    gtk_widget_set_halign(image, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(image, GTK_ALIGN_CENTER);

    // ImageEditor クラスのインスタンス化
    ImageEditor* editor = new ImageEditor(GTK_IMAGE(image));
    g_object_set_data(G_OBJECT(app), "editor", editor);

    // ジェスチャー入力設定
    GtkGesture* drag = gtk_gesture_drag_new();
    g_signal_connect(drag, "drag-end", G_CALLBACK(on_drag_end), editor);
    gtk_widget_add_controller(image, GTK_EVENT_CONTROLLER(drag));

    return window;
}

// --- 公開関数：アプリ起動時 (startup) ---
void on_app_startup(GApplication* app, gpointer user_data) {
    GtkBuilder* builder = gtk_builder_new_from_file("menu.ui");
    gtk_application_set_menubar(GTK_APPLICATION(app),
                                 G_MENU_MODEL(gtk_builder_get_object(builder, "appmenu")));
}

// --- 公開関数：アクティベート時 (activate) ---
void on_app_activate(GApplication* app, gpointer user_data) {
    GtkWidget* window = image_window_new(app);
    gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);

    GActionGroup* actions = (GActionGroup*)g_simple_action_group_new();
    g_action_map_add_action_entries(G_ACTION_MAP(actions),
                                      app_entries, G_N_ELEMENTS(app_entries), app);
    gtk_widget_insert_action_group(window, "app", actions);

    gtk_window_present(GTK_WINDOW(window));
}