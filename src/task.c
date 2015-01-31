#include "task.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_24;
static BitmapLayer *task_img;
static BitmapLayer *select_button;
static TextLayer *task_name;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_gothic_24 = fonts_get_system_font(FONT_KEY_GOTHIC_24);
  // task_img
  task_img = bitmap_layer_create(GRect(0, 87, 145, 67));
  bitmap_layer_set_background_color(task_img, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)task_img);
  
  // select_button
  select_button = bitmap_layer_create(GRect(115, 60, 22, 22));
  bitmap_layer_set_background_color(select_button, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)select_button);
  
  // task_name
  task_name = text_layer_create(GRect(21, 3, 83, 75));
  text_layer_set_text(task_name, "Brush teeth");
  text_layer_set_text_alignment(task_name, GTextAlignmentCenter);
  text_layer_set_font(task_name, s_res_gothic_24);
  layer_add_child(window_get_root_layer(s_window), (Layer *)task_name);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(task_img);
  bitmap_layer_destroy(select_button);
  text_layer_destroy(task_name);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_task(void) {
  initialise_ui();
  window_set_click_config_provider(s_window, (ClickConfigProvider) config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
  
  //Initializing routine variables 
  counter = 1; 
  maxRoutines = 9;
}

void hide_task(void) {
  window_stack_remove(s_window, true);
}
