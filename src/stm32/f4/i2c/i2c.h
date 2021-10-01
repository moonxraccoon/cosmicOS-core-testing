/*
 * TwoWire interface for STM32F4xx boards
 *
 * This will support both SMBus and I2C
 * 
 *
 * changelog:
 * |_____v0.1
 * |       |___ added init function (tested)
 * |       |___ added byte read function (tested)
 * |       |___ added burst byte read function
 * |       |___ added burst write function
 * |       
 *
 * @author: cosmicraccoon (aka Daniel Mironow)
 * @version: v0.1
 *
 */
#ifndef _TWOWIRE_H
#define _TWOWIRE_H

#include <stm32f4xx.h>
#include <stdbool.h>
#include "../../../bitutils.h"

#define I2C_STD_MODE    0x00
#define I2C_FAST_MODE   0x01

#define I2C_FREQ_MIN_SM     0x02
#define I2C_FREQ_MIN_FM     0x04
#define I2C_FREQ_MAX        0x32

// Standard mode timing in <s>
#define I2C_SM_SCLL         0.0000047
#define I2C_SM_SCLH         0.000004
#define I2C_SM_SCL_RISE_MAX 0.000001
#define I2C_SM_SCL_FALL_MAX 0.0000003

// Fast mode timing in <s>
#define I2C_FM_SCLL         0.0000013
#define I2C_FM_SCLH         0.0000006
#define I2C_FM_SCL_RISE_MAX 0.0000003
#define I2C_FM_SCL_FALL_MAX 0.0000003

#define I2C_DUTY_2      0x00
#define I2C_DUTY_16_9   0x01

#define I2C_READY       0x00
#define I2C_BUSY_RX     0x01
#define I2C_BUSY_TX     0x02


#define I2C_ITBUFEN_BIT     (0x0A)
#define I2C_ITEVTEN_BIT     (0x09)
#define I2C_ITERREN_BIT     (0x08)


typedef enum _twowire_err_h {
    I2C_OK,
    I2C_ERR_PORT_NOT_AVAILABLE,
    I2C_ERR_FREQ_TOO_LOW,
    I2C_ERR_FREQ_TOO_HIGH,
    I2C_ERR_BUS,
    I2C_ERR_ARBLOSS,
    I2C_ERR_AF,
    I2C_ERR_OVR,
    I2C_ERR_PEC,
    I2C_ERR_TIMEOUT,
    I2C_ERR_SMBALERT,
    I2C_ERR_PORT_UNDEFINED,
} twowire_err_t;

typedef struct __twowire_it_handle {
    uint8_t *tx_buf;
    uint8_t *rx_buf;
    uint8_t status;
} __twowire_it_handle_t;

typedef struct _I2C_port {
    I2C_TypeDef *i2c;
    uint8_t frequency;
    uint8_t mode;
    uint8_t duty;
    bool set_up;
    bool interrupt_driven;
    bool slave;
    // TODO: add other settings
} I2C_port;


twowire_err_t I2C_init(I2C_port *port);
uint8_t I2C_read(I2C_port *port, uint8_t slave, uint8_t memaddr);
twowire_err_t I2C_read_burst(I2C_port *port, uint8_t slave, uint8_t memaddr, uint8_t n, uint8_t *data);
twowire_err_t I2C_write(I2C_port *port, uint8_t slave, uint8_t memaddr, uint8_t data);
twowire_err_t I2C_write_burst(I2C_port *port, uint8_t slave, uint8_t memaddr, uint8_t n, uint8_t *data);

float _I2C_ccr_calc(I2C_port *port);
float _I2C_trise_calc(I2C_port *port);



#endif
