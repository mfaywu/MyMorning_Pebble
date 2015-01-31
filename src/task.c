#include "task.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_24;
static BitmapLayer *task_img;
static BitmapLayer *forward;
static TextLayer *task_name;

//Images
static GBitmap *arrows;
static GBitmap *toothbrush_image;
static GBitmap *breakfast_images;
static GBitmap *backpack_image;
//static GBitmap *new_play_button_image;
static GBitmap *keys_image;
static GBitmap *lightbulb_image;
static GBitmap *dressed_image;
static GBitmap *lotusflower_image;
static GBitmap *waterbottle_image;

int counter; 
int maxRoutines;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  //Upload
  dressed_image = gbitmap_create_with_resource(RESOURCE_ID_dressed_image); 
  
  //reset the layer and add another one
  if (counter == 1) {
    text_layer_set_text(task_name, "Get dressed");
    bitmap_layer_set_bitmap(task_img, dressed_image);
    gbitmap_destroy(toothbrush_image);
    lotusflower_image = gbitmap_create_with_resource(RESOURCE_ID_lotusflower_image);
    counter++;
  }
  else if (counter == 2) {
    text_layer_set_text(task_name, "Meditate");
    bitmap_layer_set_bitmap(task_img, lotusflower_image);
    gbitmap_destroy(dressed_image);
    breakfast_images = gbitmap_create_with_resource(RESOURCE_ID_breakfast_image);
    counter++;
  }
  else if (counter == 3) {
    text_layer_set_text(task_name, "Eat b'fast");
    bitmap_layer_set_bitmap(task_img, breakfast_images);
    gbitmap_destroy(lotusflower_image);
    backpack_image = gbitmap_create_with_resource(RESOURCE_ID_backpack_image);
    counter++;
  }
  else if (counter == 4) {
    text_layer_set_text(task_name, "Pack b'pack");
    bitmap_layer_set_bitmap(task_img, backpack_image);
    gbitmap_destroy(breakfast_images);
    waterbottle_image = gbitmap_create_with_resource(RESOURCE_ID_waterbottle_image);
    counter++;
  }
  else if (counter == 5) {
    text_layer_set_text(task_name, "Get more h2o");
    bitmap_layer_set_bitmap(task_img, waterbottle_image);
    gbitmap_destroy(backpack_image);
    keys_image = gbitmap_create_with_resource(RESOURCE_ID_keys_image);
    counter++;
  }
  else if (counter == 6) {
    text_layer_set_text(task_name, "Get keys");
    bitmap_layer_set_bitmap(task_img, keys_image);
    gbitmap_destroy(waterbottle_image);
    lightbulb_image = gbitmap_create_with_resource(RESOURCE_ID_lightbulb_image);
    counter++;
  }
  else if (counter == 7) {
    text_layer_set_text(task_name, "Turn off lights");
    bitmap_layer_set_bitmap(task_img, lightbulb_image);
    gbitmap_destroy(keys_image);
    counter++;
  }
  else if (counter == maxRoutines) {
    text_layer_set_text(task_name, "Done with routines!");   
    gbitmap_destroy(lightbulb_image);
    static GBitmap *sunrise;
    window_set_background_color (s_window, GColorBlack);
    text_layer_set_background_color (task_name, GColorBlack);
    text_layer_set_text_color(task_name, GColorWhite);
    sunrise = gbitmap_create_with_resource(RESOURCE_ID_SUNRISE_IMAGE);
    bitmap_layer_set_bitmap(task_img, sunrise);
  }
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) { }

static void down_click_handler(ClickRecognizerRef recognizer, void *context) { }

static void config_provider(Window *window) {
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_gothic_24 = fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
  // task_img
  task_img = bitmap_layer_create(GRect(0, 85, 145, 67));
  //bitmap_layer_set_background_color(task_img, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)task_img);
  bitmap_layer_set_bitmap(task_img, toothbrush_image);
  
  // forward
  forward = bitmap_layer_create(GRect(115, 60, 22, 22));
  //bitmap_layer_set_background_color(forward, GColorBlack);
  arrows = gbitmap_create_with_resource(RESOURCE_ID_play_icon);
  bitmap_layer_set_bitmap(forward, arrows);
  layer_add_child(window_get_root_layer(s_window), (Layer *)forward);
 
  // task_name
  task_name = text_layer_create(GRect(21, 9, 83, 59));
  text_layer_set_text(task_name, "Brush teeth");
  toothbrush_image = gbitmap_create_with_resource(RESOURCE_ID_brush_teeth_image);
  bitmap_layer_set_bitmap(task_img, toothbrush_image);
  text_layer_set_text_alignment(task_name, GTextAlignmentCenter);
  text_layer_set_font(task_name, s_res_gothic_24);
  layer_add_child(window_get_root_layer(s_window), (Layer *)task_name);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(task_img);
  bitmap_layer_destroy(forward);
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
  window_set_click_config_provider(s_window, (ClickConfigProvider) config_provider);
  
  window_stack_push(s_window, true);
  
  //Initializing routine variables 
  counter = 1; 
  maxRoutines = 8;
}

void hide_task(void) {
  window_stack_remove(s_window, true);
}