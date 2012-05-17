#include <gtk/gtk.h>
#include <webkit/webkit.h>

static void destroyWindowCb(GtkWidget* widget, GtkWidget* window);
static gboolean closeWebViewCb(WebKitWebView* webView, GtkWidget* window);

int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GObject *main_window;
  GtkWidget *scrolledWindow;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "builder.ui", NULL);

  // Create a browser instance
  WebKitWebView *webView = WEBKIT_WEB_VIEW(webkit_web_view_new());

  /* Connect signal handlers to the constructed widgets. */
  main_window = gtk_builder_get_object (builder, "main_window");
  g_signal_connect (main_window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  scrolledWindow = GTK_WIDGET(gtk_builder_get_object (builder, "scrolledWindow"));
  gtk_container_add(GTK_CONTAINER(scrolledWindow), GTK_WIDGET(webView));

  // Set up callbacks so that if either the main window or the browser instance is
  // closed, the program will exit
  g_signal_connect(main_window, "destroy", G_CALLBACK(destroyWindowCb), NULL);
  g_signal_connect(webView, "close-web-view", G_CALLBACK(closeWebViewCb), main_window);

  // Load a web page into the browser instance
  webkit_web_view_load_uri(webView, "http://www.google.com/");

  // webView in not shown yet
  gtk_widget_show_all(GTK_WIDGET(main_window));

  gtk_main ();

  return 0;
}

static void destroyWindowCb(GtkWidget* widget, GtkWidget* window)
{
    gtk_main_quit();
}

static gboolean closeWebViewCb(WebKitWebView* webView, GtkWidget* window)
{
    gtk_widget_destroy(window);
    return TRUE;
}

