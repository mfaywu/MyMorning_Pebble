#include <pebble.h>
#include "homescreen.h"

Window *window;

int main(void) {
  show_homescreen();
  app_event_loop();
  hide_homescreen();
}