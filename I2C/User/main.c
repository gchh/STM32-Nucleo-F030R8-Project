#include "main.h"


int main(void)
{
	//LED2-PA5
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;  //打开Port A时钟
	GPIOA->MODER &= (~GPIO_MODER_MODER5);
	GPIOA->MODER |=GPIO_MODER_MODER5_0; //PA5输出
	GPIOA->OTYPER &= (~GPIO_OTYPER_OT_5); //PA5推挽输出
	//GPIOA->PUPDR &= (~GPIO_PUPDR_PUPDR5);
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPDR5_0; //PA5 PULL-UP

	//I2C1_SCL-PB6; I2C1_SDA-PB7
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;  //打开Port B时钟
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;  //打开I2C1时钟
	RCC->CFGR3 |= RCC_CFGR3_I2C1SW_SYSCLK;//I2C1时钟源选择SYSCLK
	GPIOB->MODER |= GPIO_MODER_MODER7_1 | GPIO_MODER_MODER6_1;//PB6 PB7复用功能
	GPIOB->AFR[0] |= (1<<28) | (1<<24);//PB6-AF1 PB7-AF1
	GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR6 | GPIO_OSPEEDR_OSPEEDR7;//PB6 PB7高速
	GPIOB->OTYPER |= GPIO_OTYPER_OT_6 | GPIO_OTYPER_OT_7;//PB6 PB7开漏输出
	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR6_0 | GPIO_PUPDR_PUPDR7_0;//PB6 PB7上拉
	
	I2C1->CR1 &= ~I2C_CR1_PE;//先关闭I2C1
	
	while(1)
	{
			GPIOA->ODR ^= GPIO_ODR_5;
			//SET_LED2;
			//CLR_SET_LED2_BIT;

			//RESET_LED2;
			//CLR_RESET_LED2_BIT;
	}
}
