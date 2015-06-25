#include <pebble.h>

static Window *window;
static TextLayer *s_time_layer;
static TextLayer *s_date_layer;
static GBitmap *s_bitmap;
static BitmapLayer *s_bitmap_layer;
static uint32_t images[] = {RESOURCE_ID_PONY01,
                            RESOURCE_ID_PONY02,
                            RESOURCE_ID_PONY03,
                            RESOURCE_ID_PONY04,
                            RESOURCE_ID_PONY05,
                            RESOURCE_ID_PONY06,
                            RESOURCE_ID_PONY07,
                            RESOURCE_ID_PONY08,
                            RESOURCE_ID_PONY09,
                            RESOURCE_ID_PONY10,
                            RESOURCE_ID_PONY11,
                            RESOURCE_ID_PONY12,
                            RESOURCE_ID_PONY13,
                            RESOURCE_ID_PONY14,
                            RESOURCE_ID_PONY15,
                            RESOURCE_ID_PONY16,
                            RESOURCE_ID_PONY17,
                            RESOURCE_ID_PONY18,
                            RESOURCE_ID_PONY19,
                            RESOURCE_ID_PONY20,
                            RESOURCE_ID_PONY21,
                            RESOURCE_ID_PONY22,
                            RESOURCE_ID_PONY23,
                            RESOURCE_ID_PONY24,
                            RESOURCE_ID_PONY25,
                            RESOURCE_ID_PONY26,
                            RESOURCE_ID_PONY27,
                            RESOURCE_ID_PONY28,
                            RESOURCE_ID_PONY29,
                            RESOURCE_ID_PONY30,
                            RESOURCE_ID_PONY31,
                            RESOURCE_ID_PONY32,
                            RESOURCE_ID_PONY33,
                            RESOURCE_ID_PONY34,
                            RESOURCE_ID_PONY35,
                            RESOURCE_ID_PONY36,
                            RESOURCE_ID_PONY37,
                            RESOURCE_ID_PONY38,
                            RESOURCE_ID_PONY39,
                            RESOURCE_ID_PONY40,
                            RESOURCE_ID_PONY41,
                            RESOURCE_ID_PONY42,
                            RESOURCE_ID_PONY43,
                            RESOURCE_ID_PONY44,
                            RESOURCE_ID_PONY45,
                            RESOURCE_ID_PONY46,
                            RESOURCE_ID_PONY47,
                            RESOURCE_ID_PONY48,
                            RESOURCE_ID_PONY49,
                            RESOURCE_ID_PONY50,
                            RESOURCE_ID_PONY51,
                            RESOURCE_ID_PONY52,
                            RESOURCE_ID_PONY53,
                            RESOURCE_ID_PONY54,
                            RESOURCE_ID_PONY55,
                            RESOURCE_ID_PONY56,
                            RESOURCE_ID_PONY57,
                            RESOURCE_ID_PONY58,
                            RESOURCE_ID_PONY59,
                            RESOURCE_ID_PONY60,
                            RESOURCE_ID_PONY61,
                            RESOURCE_ID_PONY62,
                            RESOURCE_ID_PONY63,
                            RESOURCE_ID_PONY64,
                            RESOURCE_ID_PONY65,
                            RESOURCE_ID_PONY66,
                            RESOURCE_ID_PONY67,
                            RESOURCE_ID_PONY68,
                            RESOURCE_ID_PONY69,
                            RESOURCE_ID_PONY70};

static void update_time() {
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  static char buffer[] = "00:00";
  static char date_text[] = "Xxx, Xxx 00";

  strftime(date_text, sizeof(date_text), "%a, %b %e", tick_time);
  text_layer_set_text(s_date_layer, date_text);

  if(clock_is_24h_style() == true) {
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
    if(buffer[0] == '0') {
        memmove(buffer, &buffer[1], sizeof(buffer) - 1);
    }
  }

  text_layer_set_text(s_time_layer, buffer);

  gbitmap_destroy(s_bitmap);
  int image = rand() % (sizeof(images) / sizeof(images[0]));
  s_bitmap = gbitmap_create_with_resource(images[image]);
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_time_layer = text_layer_create(GRect(0, 168-56, 144, 56));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  s_date_layer = text_layer_create(GRect(0, 0, 144, 40));
  text_layer_set_background_color(s_date_layer, GColorClear);
  text_layer_set_text_color(s_date_layer, GColorBlack);
  text_layer_set_text(s_date_layer, "Xxx, Xxx 00");
  text_layer_set_font(s_date_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);

  s_bitmap = gbitmap_create_with_resource(images[0]);
  s_bitmap_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
  bitmap_layer_set_compositing_mode(s_bitmap_layer, GCompOpSet);

  layer_add_child(window_layer, bitmap_layer_get_layer(s_bitmap_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_date_layer));

  update_time();
}

static void window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_date_layer);
  bitmap_layer_destroy(s_bitmap_layer);
  gbitmap_destroy(s_bitmap);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
