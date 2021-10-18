#ifndef _COSMIC_TIMER_H
#define _COSMIC_TIMER_H
#include "stm32f4xx.h"
#include <stdbool.h>

#define NULL (void*)0

#define TIM_MAX_PSC     (0xFFFF)
#define TIM_MAX_ARR     (0xFFFF)

#define TIM_DIR_OFFSET  (0x04)

#define TIM_UIE  (1U << 0x00)
#define TIM_TIE  (1U << 0x06)

#define TIM_UIE_FLAG    (1U << 0x00)

void (*tim2_it_func)();
void (*tim3_it_func)();
void (*tim4_it_func)();
void (*tim5_it_func)();
void (*tim1_it_func)();
void (*tim9_it_func)();
void (*tim10_it_func)();
void (*tim11_it_func)();

typedef enum {
    TIM_DIR_UP   = (0 << TIM_DIR_OFFSET),
    TIM_DIR_DOWN = (1 << TIM_DIR_OFFSET),
} tim_dir_t;

typedef struct timer_port {
    TIM_TypeDef *timer; 
    uint32_t prescaler;
    uint32_t autoreload;
    tim_dir_t dir;
    bool interrup_en; 
    void (*func)(void);
} timer_port_t;

typedef enum timer_err {
    TIM_OK,
    TIM_ERR_CONFIG_NO_TIMER,
    TIM_ERR_CONFIG_PRESCALER,
    TIM_ERR_CONFIG_AUTORELOAD
} tim_err_t;


tim_err_t TIM_init(const struct timer_port *port);

tim_err_t TIM_set_prescaler(const struct timer_port *port);
tim_err_t TIM_set_autoreload(const struct timer_port *port);
tim_err_t TIM_set_dir(const struct timer_port *port);

tim_err_t TIM_reset_count(const struct timer_port *port);

bool TIM_is_TIM2_5(const struct timer_port *port);
void TIM_rcc_enable(const struct timer_port *port);
void TIM_rcc_disable(const struct timer_port *port);

void _TIM_NVIC_enable(const struct timer_port *port);







uint32_t millis();
uint32_t micros();

#endif
