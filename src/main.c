#include "mgos.h"
#include "mgos_i2c.h"
#include "mgos_ccs811.h"
#include "mgos_bme280.h"
#include "bme280.h"

static struct mgos_ccs811 *s_ccs811;
static struct mgos_bme280 *s_bme280;

static void timer_cb(void *user_data) {
  float eco2, tvoc;
  float getTemp, getHum, getPr;
  getTemp=mgos_bme280_read_temperature(s_bme280);
  getPr=mgos_bme280_read_pressure(s_bme280);
  getHum=mgos_bme280_read_humidity(s_bme280);
  eco2=mgos_ccs811_get_eco2(s_ccs811);
  tvoc=mgos_ccs811_get_tvoc(s_ccs811);

  LOG(LL_INFO, ("ccs811 eCO2=%.0fppm TVOC=%.0fppb", eco2, tvoc));
  LOG(LL_INFO, ("BME280 temp=%.0f  hum=%.0f  Pr=%.0f", getTemp, getHum, getPr));

  (void) user_data;
}

enum mgos_app_init_result mgos_app_init(void) {
  struct mgos_i2c *i2c;
  s_bme280=mgos_bme280_i2c_create(0x77);
  i2c=mgos_i2c_get_global();
  if (!i2c) {
    LOG(LL_ERROR, ("I2C bus missing, set i2c.enable=true in mos.yml"));
  } else {
    s_ccs811=mgos_ccs811_create(i2c, 0x5a); // Default I2C address
    if (s_ccs811) {
      mgos_set_timer(5000, true, timer_cb, NULL);
    } else {
      LOG(LL_ERROR, ("Could not initialize sensor"));
    }
  }
  return MGOS_APP_INIT_SUCCESS;
}
