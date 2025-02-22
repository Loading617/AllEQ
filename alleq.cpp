#include <gtk/gtk.h> 
#include <json-glib/json-glib.h> 
#include <fstream> 
#include <iostream>

static GtkWidget *sliders[10];

static void apply_preset(const gdouble *values) { for (int i = 0; i < 10; i++) { gtk_range_set_value(GTK_RANGE(sliders[i]), values[i]); } }

static void on_preset_changed(GtkComboBoxText *combo, gpointer user_data) { const gchar *preset = gtk_combo_box_text_get_active_text(combo); if (g_strcmp0(preset, "Rock") == 0) { gdouble rock_preset[10] = {3, 6, 9, 6, 3, 0, -3, -6, -9, -12}; apply_preset(rock_preset); } else if (g_strcmp0(preset, "Jazz") == 0) { gdouble jazz_preset[10] = {-3, 0, 3, 6, 6, 6, 3, 0, -3, -6}; apply_preset(jazz_preset); } g_free((gpointer)preset); }

static void save_custom_profile() { JsonBuilder *builder = json_builder_new(); json_builder_begin_object(builder); json_builder_set_member_name(builder, "custom_profile"); json_builder_begin_array(builder); for (int i = 0; i < 10; i++) { json_builder_add_double_value(builder, gtk_range_get_value(GTK_RANGE(sliders[i]))); } json_builder_end_array(builder); json_builder_end_object(builder);

JsonGenerator *gen = json_generator_new();
JsonNode *root = json_builder_get_root(builder);
json_generator_set_root(gen, root);
gchar *json_data = json_generator_to_data(gen, NULL);

std::ofstream file("equalizer_preset.json");
file << json_data;
file.close();

g_free(json_data);
json_node_free(root);
g_object_unref(builder);
g_object_unref(gen);

}

static void activate(GtkApplication *app, gpointer user_data) { GtkWidget *window = gtk_application_window_new(app); gtk_window_set_title(GTK_WINDOW(window), "System Equalizer"); gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);

GtkWidget *grid = gtk_grid_new();
gtk_container_add(GTK_CONTAINER(window), grid);

GtkWidget *combo = gtk_combo_box_text_new();
gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Rock");
gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Jazz");
g_signal_connect(combo, "changed", G_CALLBACK(on_preset_changed), NULL);
gtk_grid_attach(GTK_GRID(grid), combo, 0, 0, 2, 1);

for (int i = 0; i < 10; i++) {
    sliders[i] = gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL, -12.0, 12.0, 0.1);
    gtk_range_set_value(GTK_RANGE(sliders[i]), 0);
    gtk_grid_attach(GTK_GRID(grid), sliders[i], i, 1, 1, 1);
}

GtkWidget *save_button = gtk_button_new_with_label("Save Profile");
g_signal_connect(save_button, "clicked", G_CALLBACK(save_custom_profile), NULL);
gtk_grid_attach(GTK_GRID(grid), save_button, 0, 2, 2, 1);

gtk_widget_show_all(window);

}

int main(int argc, char **argv) { GtkApplication *app = gtk_application_new("com.example.equalizer", G_APPLICATION_FLAGS_NONE); g_signal_connect(app, "activate", G_CALLBACK(activate), NULL); int status = g_application_run(G_APPLICATION(app), argc, argv); g_object_unref(app); return status; }

