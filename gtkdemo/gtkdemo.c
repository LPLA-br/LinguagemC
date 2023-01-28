/*exemplo do manual de referência do gtk3 com mínimas modificações*/
/*construção de grandes interfaces de usuário de forma prática
utilizando o software glade para modificar o builder.ui*/
#include <gtk/gtk.h>

static void ato1(GtkWidget *widget, gpointer  data);

static void ato2(GtkWidget *widget, gpointer  data);

int main(int argc, char *argv[])
{
	GtkBuilder *builder;
	GObject *window;
	GObject *button;
	GError *error = NULL;

	gtk_init (&argc, &argv);

	/* Construct a GtkBuilder instance and load our UI description */
	/*Constroi uma instância de GtkBuilder e carrega nossa descrição*/
	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
		{
			g_printerr ("Error loading file: %s\n", error->message);
			g_clear_error (&error);
			return 1;
		}

	/* Connect signal handlers to the constructed widgets. */
	/* Conecta os manipuladores para os widgets construidos*/
	window = gtk_builder_get_object (builder, "window");
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	button = gtk_builder_get_object (builder, "1");
	g_signal_connect (button, "clicked", G_CALLBACK (ato1), NULL);

	button = gtk_builder_get_object (builder, "0");
	g_signal_connect (button, "clicked", G_CALLBACK (ato2), NULL);

	button = gtk_builder_get_object (builder, "sair");
	g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

	gtk_main ();

	return 0;
}

static void ato1(GtkWidget *widget, gpointer  data)
{
	g_print ("verdadeiro\n");
}

static void ato2(GtkWidget *widget, gpointer  data)
{
	g_print ("falso\n");
}
