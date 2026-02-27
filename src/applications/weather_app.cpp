#include <Embedded_Structs.h>
#include <close-windows.h>
#define TFT_WIDTH 410
#define TFT_HEIGHT 512
static char weather_buffer[7];
extern Weather *weather_vals;

static void update_weather_data()
{
    snprintf(weather_buffer, sizeof(weather_buffer), "%3.2f", (weather_vals->temperature - 273.15) * 9 / 5 + 32);
    lv_label_set_text_fmt(EmbeddedUI_t.temperature_label, "%s°F", weather_buffer);
    snprintf(weather_buffer, sizeof(weather_buffer), "%3.2f", weather_vals->wind_speed);
    lv_label_set_text_fmt(EmbeddedUI_t.wind_speed_label, "Wind Speed: %s MPH", weather_buffer);
    lv_label_set_text_fmt(EmbeddedUI_t.humidity_label, "Hum: %d%%", weather_vals->humidity);
}

static void create_weather_page(lv_event_t *e)
{
    if (!lv_obj_is_valid(EmbeddedUI_t.weather))
    {
        EmbeddedUI_t.weather = lv_obj_create(lv_screen_active());

        lv_obj_set_flex_flow(EmbeddedUI_t.weather, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(EmbeddedUI_t.weather, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

        EmbeddedUI_t.wind_speed_label = lv_label_create(EmbeddedUI_t.weather);
        EmbeddedUI_t.humidity_label = lv_label_create(EmbeddedUI_t.weather);
        EmbeddedUI_t.temperature_label = lv_label_create(EmbeddedUI_t.weather);
        // lv_obj_t *window = lv_obj_create(SmartWatchUI_t.weather);
        lv_obj_set_style_text_font(EmbeddedUI_t.temperature_label, &lv_font_montserrat_30, LV_PART_MAIN);
        lv_obj_set_style_text_font(EmbeddedUI_t.wind_speed_label, &lv_font_montserrat_30, LV_PART_MAIN);
        lv_obj_set_style_text_font(EmbeddedUI_t.humidity_label, &lv_font_montserrat_30, LV_PART_MAIN);
        lv_obj_set_style_margin_top(EmbeddedUI_t.wind_speed_label, 20, LV_PART_MAIN);

        EmbeddedUI_t.close_btn = lv_button_create(EmbeddedUI_t.weather);

        lv_obj_set_style_bg_color(EmbeddedUI_t.close_btn, lv_color_hex(0xfc0303), LV_PART_MAIN);
        lv_obj_t *label_close = lv_label_create(EmbeddedUI_t.close_btn);
        lv_obj_set_style_text_font(label_close, &lv_font_montserrat_40, LV_PART_MAIN);
        lv_obj_set_size(EmbeddedUI_t.close_btn, TFT_WIDTH, 80);

        lv_obj_center(label_close);
        lv_obj_set_style_margin_top(EmbeddedUI_t.close_btn, 320, LV_PART_MAIN);
        lv_label_set_text(label_close, "CLOSE");
        snprintf(weather_buffer, sizeof(weather_buffer), "%3.2f", (weather_vals->temperature - 273.15) * 9 / 5 + 32);
        lv_label_set_text_fmt(EmbeddedUI_t.temperature_label, "%s°F", weather_buffer);
        snprintf(weather_buffer, sizeof(weather_buffer), "%3.2f", weather_vals->wind_speed);
        lv_label_set_text_fmt(EmbeddedUI_t.wind_speed_label, "Wind Speed: %s MPH", weather_buffer);
        lv_label_set_text_fmt(EmbeddedUI_t.humidity_label, "Hum: %d%%", weather_vals->humidity);
        lv_obj_align(EmbeddedUI_t.close_btn, LV_ALIGN_BOTTOM_MID, 0, 0);
        // lv_obj_set_style_radius(EmbeddedUI_t.weather, 40, LV_PART_MAIN);
        // lv_obj_center(EmbeddedUI_t.close_btn);
        lv_obj_set_size(EmbeddedUI_t.weather, TFT_WIDTH, TFT_HEIGHT);
        // lv_obj_center(EmbeddedUI_t.weather);
        EmbeddedUI_t.datetime_timer = lv_timer_create((lv_timer_cb_t)update_weather_data, 1000, NULL);
        lv_obj_add_event_cb(EmbeddedUI_t.close_btn, close_window_cb, LV_EVENT_CLICKED, NULL);
    }
}