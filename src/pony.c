#include <pebble.h>

// Function prototypes
static void init(void);
static void deinit(void);
static void update_time(bool new_image);

static int i;
static Window *window;
static TextLayer* s_time_layer;
static TextLayer* s_time_shadow_layers[4];
static TextLayer* s_date_layer;
static TextLayer* s_date_shadow_layers[4];
static Layer* battery_layer;
static Layer* background_layer;
static GBitmap* s_bitmap;
static BitmapLayer *s_bitmap_layer;
static GColor foreground_color;
static GColor background_color;
// There's probably a better way to do this:
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

static void app_message_inbox_received(DictionaryIterator *iterator, void *context) {
  Tuple *t = dict_find(iterator, 0);
  bool black_on_white = t->value->int32;
  status_t s = persist_write_bool(0, black_on_white);
  if (black_on_white) {
    foreground_color = GColorBlack;
    background_color = GColorWhite;
  } else {
    foreground_color = GColorWhite;
    background_color = GColorBlack;
  }

  text_layer_set_text_color(s_time_layer, foreground_color);
  for (i = 0; i < 4; i++) {
    text_layer_set_text_color(s_time_shadow_layers[i], background_color);
  }
  text_layer_set_text_color(s_date_layer, foreground_color);
  for (i = 0; i < 4; i++) {
    text_layer_set_text_color(s_date_shadow_layers[i], background_color);
  }
  update_time(false);
}

static void draw_background(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, background_color);
  graphics_fill_rect(ctx, bounds, 0, GCornerNone);
}

static void draw_battery(Layer *layer, GContext *ctx) {
  BatteryChargeState charge_state = battery_state_service_peek();
  GRect bounds = layer_get_bounds(layer);

  // Draw background color around battery meter
  graphics_context_set_stroke_color(ctx, background_color);
  graphics_context_set_fill_color(ctx, background_color);
  graphics_fill_rect(ctx, GRect(0,0,14,7), 0, GCornerNone);
  graphics_draw_line(ctx, GPoint(14,1), GPoint(14,5));
  // Draw battery meter border
  graphics_context_set_stroke_color(ctx, foreground_color);
  graphics_context_set_fill_color(ctx, foreground_color);
  graphics_draw_rect(ctx, GRect(1,1,12,5));
  graphics_draw_line(ctx, GPoint(13,2), GPoint(13,4));
  // Draw battery meter
  graphics_fill_rect(ctx, GRect(2,2,charge_state.charge_percent/10,3), 0, GCornerNone);
}

static void update_time(bool new_image) {
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  static char buffer[] = "00:00";
  static char date_text[] = "Xxx, Xxx 00";

  if(clock_is_24h_style() == true) {
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
    if(buffer[0] == '0') {
        memmove(buffer, &buffer[1], sizeof(buffer) - 1);
    }
  }
  text_layer_set_text(s_time_layer, buffer);
  for (i = 0; i < 4; i++) {
    text_layer_set_text(s_time_shadow_layers[i], buffer);
  }

  strftime(date_text, sizeof(date_text), "%a, %b %e", tick_time);
  text_layer_set_text(s_date_layer, date_text);
  for (i = 0; i < 4; i++) {
    text_layer_set_text(s_date_shadow_layers[i], date_text);
  }

  if (new_image) {
    gbitmap_destroy(s_bitmap);
    int image = rand() % (sizeof(images) / sizeof(images[0]));
    s_bitmap = gbitmap_create_with_resource(images[image]);
    bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
  }
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time(true);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Add the background color layer
  background_layer = layer_create(bounds);
  layer_set_update_proc(background_layer, draw_background);
  layer_add_child(window_layer, background_layer);

  // Create the layer used for the images
  int image = rand() % (sizeof(images) / sizeof(images[0]));
  s_bitmap = gbitmap_create_with_resource(images[image]);
  s_bitmap_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
  bitmap_layer_set_compositing_mode(s_bitmap_layer, GCompOpSet);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_bitmap_layer));

  // Set up the time text
  s_time_layer = text_layer_create(GRect(0, 168-56, 144, 56));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, foreground_color);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Around the time text put four copies in the opposite color for readability
  s_time_shadow_layers[0] = text_layer_create(GRect(2, 168-56+2, 144, 56));
  s_time_shadow_layers[1] = text_layer_create(GRect(2, 168-56-2, 144, 56));
  s_time_shadow_layers[2] = text_layer_create(GRect(-2, 168-56+2, 144, 56));
  s_time_shadow_layers[3] = text_layer_create(GRect(i-2, 168-56-2, 144, 56));
  for (i = 0; i < 4; i++) {
    text_layer_set_background_color(s_time_shadow_layers[i], GColorClear);
    text_layer_set_text_color(s_time_shadow_layers[i], background_color);
    text_layer_set_text(s_time_shadow_layers[i], "00:00");
    text_layer_set_font(s_time_shadow_layers[i], fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49));
    text_layer_set_text_alignment(s_time_shadow_layers[i], GTextAlignmentCenter);
    layer_add_child(window_layer, text_layer_get_layer(s_time_shadow_layers[i]));
  }
  // Add the time text afterwards so it is on top
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));

  // Set up the date text
  s_date_layer = text_layer_create(GRect(0, 0, 144, 40));
  text_layer_set_background_color(s_date_layer, GColorClear);
  text_layer_set_text_color(s_date_layer, foreground_color);
  text_layer_set_text(s_date_layer, "Xxx, Xxx 00");
  text_layer_set_font(s_date_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);

  // Around the date text put four copies in the opposite color for readability
  s_date_shadow_layers[0] = text_layer_create(GRect(1, 1, 144, 40));
  s_date_shadow_layers[1] = text_layer_create(GRect(1,- 1, 144, 40));
  s_date_shadow_layers[2] = text_layer_create(GRect(-1, 1, 144, 40));
  s_date_shadow_layers[3] = text_layer_create(GRect(-1, -1, 144, 40));
  for (i = 0; i < 4; i++) {
    text_layer_set_background_color(s_date_shadow_layers[i], GColorClear);
    text_layer_set_text_color(s_date_shadow_layers[i], background_color);
    text_layer_set_text(s_date_shadow_layers[i], "Xxx, Xxx 00");
    text_layer_set_font(s_date_shadow_layers[i], fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
    text_layer_set_text_alignment(s_date_shadow_layers[i], GTextAlignmentCenter);
    layer_add_child(window_layer, text_layer_get_layer(s_date_shadow_layers[i]));
  }
  // Add the date text after so it is on top
  layer_add_child(window_layer, text_layer_get_layer(s_date_layer));

  // Add the battery meter layer
  battery_layer = layer_create(GRect(125, 5, 15, 7));
  layer_set_update_proc(battery_layer, draw_battery);
  layer_add_child(window_layer, battery_layer);

  // Update everything with the current date/time
  update_time(false);
}

static void window_unload(Window *window) {
  layer_destroy(battery_layer);
  text_layer_destroy(s_time_layer);
  for (i = 0; i < 4; i++) {
    text_layer_destroy(s_time_shadow_layers[i]);
  }
  text_layer_destroy(s_date_layer);
  for (i = 0; i < 4; i++) {
    text_layer_destroy(s_date_shadow_layers[i]);
  }
  bitmap_layer_destroy(s_bitmap_layer);
  gbitmap_destroy(s_bitmap);
}

static void init(void) {
  bool black_on_white = true;
  if (persist_exists(0)) {
    black_on_white = persist_read_bool(0);
  } else {
    persist_write_bool(0, black_on_white);
  }
  if (black_on_white) {
    foreground_color = GColorBlack;
    background_color = GColorWhite;
  } else {
    foreground_color = GColorWhite;
    background_color = GColorBlack;
  }

  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  app_message_register_inbox_received(app_message_inbox_received);
  app_message_open(30, 0);
}

static void deinit(void) {
  tick_timer_service_unsubscribe();
  app_message_deregister_callbacks();
  window_stack_pop_all(true);
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
