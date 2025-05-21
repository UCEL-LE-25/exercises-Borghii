#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWindow *parent = GTK_WINDOW(data);

    // Crear el diálogo
    GtkWidget *dialog = gtk_dialog_new_with_buttons(
        "Introduce tu nombre",
        parent,
        GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
        "_Cancelar", GTK_RESPONSE_CANCEL,
        "_Aceptar", GTK_RESPONSE_OK,
        NULL
    );

    // Obtener la caja de contenido del diálogo
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Crear una etiqueta y una entrada de texto
    GtkWidget *label = gtk_label_new("¿Cómo te llamas?");
    GtkWidget *entry = gtk_entry_new();

    // Añadir los widgets al contenido del diálogo
    gtk_box_pack_start(GTK_BOX(content_area), label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(content_area), entry, FALSE, FALSE, 5);

    gtk_widget_show_all(dialog);

    // Ejecutar el diálogo y capturar la respuesta
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK) {
        const gchar *nombre = gtk_entry_get_text(GTK_ENTRY(entry));

        // Mostrar otro diálogo con el saludo
        GtkWidget *saludo_dialog = gtk_message_dialog_new(
            parent,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK,
            "¡Hola, %s! 😄", nombre
        );
        gtk_window_set_title(GTK_WINDOW(saludo_dialog), "Saludo");
        gtk_dialog_run(GTK_DIALOG(saludo_dialog));
        gtk_widget_destroy(saludo_dialog);
    }

    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK + Entrada");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    GtkWidget *button = gtk_button_new_with_label("Saludar");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), window);

    gtk_container_add(GTK_CONTAINER(window), button);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
