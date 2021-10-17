
#include "timer.h"
#include "stm32f4xx.h"


uint32_t millis() {
    return TIM5->CNT;
}

uint32_t micros() {
    return TIM5->CNT;
}

