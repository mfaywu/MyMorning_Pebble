#include "homescreen.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_play_icon;
static GFont s_res_gothic_28_bold;
static BitmapLayer *sunrise;
static BitmapLayer *start_button;
static TextLayer *start_text;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_play_icon = gbitmap_create_with_resource(RESOURCE_ID_play_icon);
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // sunrise
  sunrise = bitmap_layer_create(GRect(0, 87, 145, 65));
  bitmap_layer_set_background_color(sunrise, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)sunrise);
  
  // start_button
  start_button = bitmap_layer_create(GRect(115, 60, 22, 22));
  bitmap_layer_set_bitmap(start_button, s_res_play_icon);
  layer_add_child(window_get_root_layer(s_window), (Layer *)start_button);
  
  // start_text
  start_text = text_layer_create(GRect(17, 20, 83, 59));
  text_layer_set_text(start_text, "Start my morning!");
  text_layer_set_font(start_text, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)start_text);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(sunrise);
  bitmap_layer_destroy(start_button);
  text_layer_destroy(start_text);
  gbitmap_destroy(s_res_play_icon);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_homescreen(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_homescreen(void) {
  window_stack_remove(s_window, true);
}
