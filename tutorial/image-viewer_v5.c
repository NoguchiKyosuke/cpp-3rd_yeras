#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

static void
on_quit (GtkWidget* button, gpointer* user_data) {
    g_application_quit (G_APPLICATION(user_data));
}

static void
set_image (GtkImage* image, char* filename) {
    if (filename) {
        GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
        int w = gdk_pixbuf_get_width (pixbuf);
        int h = gdk_pixbuf_get_height (pixbuf);
        gtk_image_set_from_pixbuf (image, pixbuf);
        gtk_widget_set_size_request (GTK_WIDGET(image), w, h);
    }
}

static void
on_startup (GApplication* app, gpointer* user_data) {
    GtkBuilder* builder = gtk_builder_new_from_file ("menu.ui");
    gtk_application_set_menubar(GTK_APPLICATION(app),
                                 G_MENU_MODEL(gtk_builder_get_object(builder, "appmenu")));
}

static GtkWidget*
image_window_new (GApplication* app) {
    GtkWidget* window = gtk_application_window_new (GTK_APPLICATION (app));
    gtk_window_set_title (GTK_WINDOW(window), "Image viewer");
    gtk_window_set_default_size (GTK_WINDOW(window), 400, 300);

    GtkWidget* scrolled_window = gtk_scrolled_window_new ();
    gtk_widget_set_vexpand (scrolled_window, TRUE);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(scrolled_window),
                                    GTK_POLICY_AUTOMATIC,
                                    GTK_POLICY_AUTOMATIC);
    gtk_window_set_child (GTK_WINDOW(window), scrolled_window);

    GtkWidget* image = gtk_image_new ();
    gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW(scrolled_window), image);
    gtk_widget_set_hexpand (image, FALSE);
    gtk_widget_set_vexpand (image, FALSE);
    gtk_widget_set_halign (image, GTK_ALIGN_CENTER);
    gtk_widget_set_valign (image, GTK_ALIGN_CENTER);
    set_image (GTK_IMAGE(image), "Parrots.png");

    return window;
}

static void
on_menu_open (GSimpleAction* action,
              GVariant* parameter,
              gpointer user_data) {
    printf ("This function is not implemented yet.\n");
}

static void
on_menu_quit (GSimpleAction* action,
              GVariant* parameter,
              gpointer user_data) {
    g_application_quit (G_APPLICATION(user_data));
}

static GActionEntry app_entries[] = {
    {"menu_open", on_menu_open, NULL, NULL, NULL},
    {"menu_quit", on_menu_quit, NULL, NULL, NULL}
};

static void
on_activate (GApplication* app, gpointer* user_data) {
    GtkWidget* window = image_window_new (app);
    gtk_application_window_set_show_menubar (GTK_APPLICATION_WINDOW(window),
                                              TRUE);

    GActionGroup* actions = (GActionGroup *) g_simple_action_group_new ();
    g_action_map_add_action_entries (G_ACTION_MAP(actions),
                                      app_entries, G_N_ELEMENTS(app_entries), app);
    gtk_widget_insert_action_group (window, "app", actions);

    gtk_window_present (GTK_WINDOW(window));
}

int main (int argc, char *argv[]) {
    GtkApplication* app = gtk_application_new ("org.gtk.tutorial",
                                                G_APPLICATION_FLAGS_NONE);
    g_signal_connect (G_OBJECT(app), "startup", G_CALLBACK(on_startup), NULL);
    g_signal_connect (G_OBJECT(app), "activate", G_CALLBACK(on_activate), NULL);
    g_application_run (G_APPLICATION(app), argc, argv);

    return 0;
}