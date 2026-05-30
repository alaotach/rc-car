#include "Camera.h"
#include "esp_camera.h"

bool CameraM::init(){
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = 30;
    config.pin_d1 = 27;
    config.pin_d2 = 26;
    config.pin_d3 = 31;
    config.pin_d4 = 32;
    config.pin_d5 = 33;
    config.pin_d6 = 35;
    config.pin_d7 = 37;
    config.pin_xclk = 40;
    config.pin_pclk = 36;
    config.pin_vsync = 21;
    config.pin_href = 34;
    config.pin_sscb_sda = 41;
    config.pin_sscb_scl = 42;;
    config.pin_pwdn = 38;
    config.pin_reset = 39;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
    
    return esp_camera_init(&config) == ESP_OK;
}