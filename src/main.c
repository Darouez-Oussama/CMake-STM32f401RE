#include "stm32f4xx_hal.h"

int main(void) {
    HAL_Init();  /* HAL init */

    __HAL_RCC_GPIOA_CLK_ENABLE();  /* Enable GPIOA clock */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5;  /* e.g., PA5 for LED */
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    while(1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(500);  /* 500ms delay */
    }
}