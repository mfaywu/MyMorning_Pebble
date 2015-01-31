#include "homescreen.h"
#include "task.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_sunrise_image;
static GBitmap *s_res_play_icon;
static GFont s_res_gothic_28_bold;
static BitmapLayer *sunrise;
static BitmapLayer *start_button;
static TextLayer *start_text;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_task();   
}

static void config_provider(Window *window) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, false);
  
  s_res_sunrise_image = gbitmap_create_with_resource(RESOURCE_ID_SUNRISE_IMAGE);
  s_res_play_icon = gbitmap_create_with_resource(RESOURCE_ID_play_icon);
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // sunrise
  sunrise = bitmap_layer_create(GRect(0, 85, 145, 67));
  bitmap_layer_set_bitmap(sunrise, s_res_sunrise_image);
  bitmap_layer_set_background_color(sunrise, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)sunrise);
  
  // start_button
  start_button = bitmap_layer_create(GRect(115, 60, 22, 22));
  bitmap_layer_set_bitmap(start_button, s_res_play_icon);
  layer_add_child(window_get_root_layer(s_window), (Layer *)start_button);
  
  // start_text
  start_text = text_layer_create(GRect(21, 3, 83, 59));
  text_layer_set_background_color(start_text, GColorBlack);
  text_layer_set_text_color(start_text, GColorWhite);
  text_layer_set_text(start_text, "Start my morning!");
  text_layer_set_font(start_text, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)start_text);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(sunrise);
  bitmap_layer_destroy(start_button);
  text_layer_destroy(start_text);
  gbitmap_destroy(s_res_sunrise_image);
  gbitmap_destroy(s_res_play_icon);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_homescreen(void) {
  initialise_ui();
  window_set_click_config_provider(s_window, (ClickConfigProvider) config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_homescreen(void) {
  window_stack_remove(s_window, true);
}
