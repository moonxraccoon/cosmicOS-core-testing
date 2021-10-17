#include "delay.h"
#include <stm32f4xx.h>
#include "../rcc/rcc.h"
#include "../timer/timer.h"

volatile uint32_t syscount = 0;

void delayMs(uint32_t ms) {
    SysTick->LOAD = (apb1_freq/1000);
    SysTick->VAL = 0x00;

    SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;
    for(int i = 0; i < ms; i++) {
        while((SysTick->CTRL & CTRL_COUNTFLAG) == 0);
    }

    SysTick->CTRL = 0x00;
}


void delayUs(uint32_t us) {
    SysTick->LOAD = (apb1_freq/1000)/1000;
    SysTick->VAL = 0x00;

    SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;
    for (int i = 0; i < us; i++) {
        while((SysTick->CTRL & CTRL_COUNTFLAG) == 0);
    }

    SysTick->CTRL = 0x00;
}

void smart_delay_ms(uint32_t ms) {
    uint32_t last_time = millis();
    while(millis() - last_time >= ms); 
}

// NEW DELAY FUNCTIONS

void delay_ms(uint32_t ms) {
    
}

void delay_us(uint32_t us) {

}

uint32_t millis() {
    return syscount;
}

void SysTick_Handler(void) {
    if (SysTick->CTRL & CTRL_COUNTFLAG) {
        syscount++;
    }
}
