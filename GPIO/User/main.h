#include "stm32f0xx.h"
#include "flash_as_eeprom.h"

#define SET_LED2 GPIOA->BSRR |= GPIO_BSRR_BS_5
#define CLR_SET_LED2_BIT GPIOA->BSRR &= ~GPIO_BSRR_BS_5

#define RESET_LED2 GPIOA->BSRR |= GPIO_BSRR_BR_5
#define CLR_RESET_LED2_BIT GPIOA->BSRR &= ~GPIO_BSRR_BR_5
