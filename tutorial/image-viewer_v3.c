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
on_activate (GApplication* app, gpointer* user_data) {
    GtkWidget* window = gtk_application_window_new (GTK_APPLICATION (app));
    gtk_window_set_title (GTK_WINDOW(window), "Image viewer");
    gtk_window_set_default_size (GTK_WINDOW(window), 400, 300);

    GtkWidget* box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child (GTK_WINDOW(window), box);

    GtkWidget* image = gtk_image_new ();
    gtk_box_append (GTK_BOX(box), image);
    set_image (GTK_IMAGE(image), "Parrots.png");

    GtkWidget* button = gtk_button_new_with_label ("Quit");
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(on_quit), app);
    gtk_box_append (GTK_BOX(box), button);

    gtk_window_present (GTK_WINDOW(window));
}

int main (int argc, char *argv[]) {
    GtkApplication* app = gtk_application_new ("org.gtk.tutorial",
                                                G_APPLICATION_FLAGS_NONE);
    char* filename = NULL;
    g_signal_connect (G_OBJECT(app),
                      "activate", G_CALLBACK(on_activate), NULL);
    g_application_run (G_APPLICATION(app), argc, argv);

    return 0;
}