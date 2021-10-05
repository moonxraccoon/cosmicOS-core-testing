#include <stm32f4xx.h>
#include <stdbool.h>
#include "stm32/f4/gpio/gpio.h"
#include "stm32/f4/delay/delay.h"
#include "stm32/f4/uart/uart.h"
#include "stm32/f4/i2c/i2c.h" 
#include "bitutils.h"
//#include "stm32/f4/rcc/rcc.h"
//#include "stm32/f4/exti/exti.h"

#define MPU_ADDR    0x68
#define DEBUG_LED   PB8
#define TEST_LED    PA8


uint16_t read_x(I2C_port port) {
    uint8_t data1, data2;
    i2c_err_t err;
    err = I2C_read(port, MPU_ADDR, 0x3B, &data1);
    if (err != I2C_OK) {
        return 0;
    }
    err = I2C_read(port, MPU_ADDR, 0x3C, &data2);
    if (err != I2C_OK) {
        return 0;
    }
    return (data1 << 8) | data2;
}



int main(void) {
    I2C_port i2c1 = {
        .i2c = I2C1,
        .frequency = 16,
        .mode = I2C_STD_MODE,
        .duty = 0,
    };

    USART_port port = {
        .usart = USART2,
        .baud = 115200,
        .mode = USART_RX_TX_MODE,
        .stop_bits = 0,
        .parity_enable = 0,
        .parity_even_odd = 0,
        .interrupt_driven = true,
    };
    GPIO_enable(DEBUG_LED, GPIO_OUTPUT);
    GPIO_enable(PA8, GPIO_OUTPUT);
    
    USART_init(&port);   
    
    I2C_init(&i2c1);
    i2c_err_t i2c_err;
    //USART_init(USART2, 115200, USART_RX_TX_MODE, USART_STOPBITS_1, USART_PARITY_NEN, USART_PARITY_EVEN); 
    //if( EXTI_attach_gpio(GPIOB, 7, EXTI_FALLING_EDGE) != EXTI_OK) {
    //    USART_printf(USART2, "EXTI init failed...\n");
    //}
    uint8_t init[2] = {0x00, 0x00};
    i2c_err = I2C_write_burst(i2c1, MPU_ADDR, 0x6B, 1, init);
    USART_printf(port, "%s\n", I2C_get_err_str(i2c_err));
    delayMs(2000);
    
    //const clock_t *test = &RCC_25MHZ_TO_84MHZ;
    char usart_test[255] = {0};
    unsigned long int cycle = 0; 
    uint8_t bit_test = 0;
    //setbit(bit_test, 4);
    //USART_printf(&port, "Test bitutils: %d\n", bit_test);

    //USART_printf(&port, "CCR value: %.12f\n", _I2C_ccr_calc(&i2c1));
    //USART_printf(&port, "TRISE value: %.12f\n", _I2C_trise_calc(&i2c1));
    uint8_t i2c_data; 
    while (1) {
        GPIO_toggle(DEBUG_LED);
        
        //char ch = USART_getc(&port);
        //USART_printf(&port, "getc: %c\n", ch);
        //USART_scan(port, usart_test, 255);
        if (USART_available(port)) {
            USART_scan(port, usart_test, 255);
            USART_printf(port, "%s\n", usart_test);
        }
        if (USART_printf(port, "Cycle: %d\n", cycle++) != USART_OK) {
            USART_printf(port, "[x] printing did not work\n");
        }

            //GPIO_toggle(PA8);
        //USART_printf(&port, "%c", USART_read(&port));
        //USART_printf(USART2, "This is a value: %.3f\n", 2.123);
        //if ( USART_has_input(USART2) ) {
        //    USART_scanf(USART2, usart_test);
        //    USART_printf(USART2, "You typed: %s\n", usart_test);
        //}
        //USART_printf(&port, "x: %6d\n", read_x(&i2c1));
        //read_x(i2c1);
        i2c_err = I2C_read(i2c1, MPU_ADDR, 0x3C, &i2c_data);
        USART_printf(port, "%s\n", I2C_get_err_str(i2c_err)); 
        uint16_t mpu_test = read_x(i2c1); 
        USART_printf(port, "X: %d\n", read_x(i2c1));
        delayMs(500);
    }
}




//static void exti_callback(void) {
//    USART_printf(USART2, "Hello from EXIT07\n");
//}
//
//void EXTI9_5_IRQHandler(void) {
//    if (EXTI->PR & (1<<7)) {
//        // Clear PR flag
//        EXTI->PR |= (1<<7);
//        // Do something...
//        exti_callback();
//    }
//}
