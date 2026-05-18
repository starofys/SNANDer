//
// Created by yang on 2026/5/19.
//

#ifndef SNANDER_DEVICE_OPT_H
#define SNANDER_DEVICE_OPT_H
#include <stdbool.h>
#include "stdint.h"

struct EEPROM;

// 定义初始化函数的指针类型
typedef int (*device_init_t)(void);

// 定义关闭/释放资源函数的指针类型
typedef int (*device_shutdown_t)(void);

// 定义SPI发送/接收命令函数的指针类型
typedef int (*device_send_cmd_t)(unsigned int writecnt, unsigned int readcnt, const unsigned char *writearr, unsigned char *readarr);

// 定义引脚使能函数的指针类型
typedef int (*enable_pins_t)(bool enable);

// 定义配置通信速率函数的指针类型
typedef int (*config_stream_t)(unsigned int speed);


// 新增：定义 EEPROM 读取函数的指针类型
typedef int32_t (*read_eeprom_t)(uint8_t *buffer, uint32_t bytestoread, struct EEPROM *eeprom_info);

// 新增：定义 EEPROM 写入函数的指针类型
typedef int32_t (*write_eeprom_t)(uint8_t *buffer, uint32_t bytesum, struct EEPROM *eeprom_info);

typedef int32_t (*parse_eep_size_t)(char *eepromname, struct EEPROM *eeprom);

// 新增：定义 CH347 I2C 配置函数的指针类型
typedef int32_t (*i2c_config_t)(int speed);

typedef struct {
  device_init_t init;
  device_shutdown_t shutdown;
  device_send_cmd_t send_command;
  enable_pins_t enable_pins;
  config_stream_t config_stream;
  read_eeprom_t read_eeprom;
  write_eeprom_t write_eeprom;
  parse_eep_size_t parse_eep_size;
  i2c_config_t i2c_config;
} device_spi_driver_t;

extern device_spi_driver_t *device_opt;

#endif // SNANDER_DEVICE_OPT_H
