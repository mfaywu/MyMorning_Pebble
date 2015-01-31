#include "task.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static BitmapLayer *task_img;
static BitmapLayer *forward;
static BitmapLayer *backward;
static TextLayer *task_name;
int counter; 
int maxRoutines;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  //reset the layer and add another one
  if (counter == 1) {
    text_layer_set_text(task_name, "first screen");
    //bitmap_layer_set_bitmap(play_pause_img, s_res_play_image);
    counter++;
  }
  else if (counter == 2) {
    text_layer_set_text(task_name, "second screen");
    counter++;
  }
  else if (counter == 3) {
    text_layer_set_text(task_name, "second screen");
    counter++;
  }
  else if (counter == maxRoutines) 
      text_layer_set_text(task_name, "Done with routines");   
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
 
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
 
}

static void config_provider(Window *window) {
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}


static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  // task_img
  task_img = bitmap_layer_create(GRect(16, 41, 80, 80));
  bitmap_layer_set_background_color(task_img, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)task_img);
  
  // forward
  forward = bitmap_layer_create(GRect(108, 16, 30, 30));
  bitmap_layer_set_background_color(forward, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)forward);
  
  // backward
  backward = bitmap_layer_create(GRect(108, 100, 30, 30));
  bitmap_layer_set_background_color(backward, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)backward);
  
  // task_name
  task_name = text_layer_create(GRect(17, 18, 78, 20));
  text_layer_set_text(task_name, "first screen");
  text_layer_set_text_alignment(task_name, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)task_name);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(task_img);
  bitmap_layer_destroy(forward);
  bitmap_layer_destroy(backward);
  text_layer_destroy(task_name);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_task(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
  
  //Initializing routine variables 
  counter = 1; 
  maxRoutines = 3;
}

void hide_task(void) {
  window_stack_remove(s_window, true);
}
