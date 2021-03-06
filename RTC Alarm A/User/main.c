/******************************************************************************
   当日历时间和闹钟A设置的时间相等时，LED2电平翻转；
   设置日历时间日期和闹钟A时间时，必须将它们一次写入相应寄存器中，
   分开写入会造成寄存器中的值不是所写入的值。如：
   rtc_time = (uint32_t)(0x22)<<16;//hour
   rtc_time |= (uint32_t)(0x38)<<8;//minute
   rtc_time |= (uint32_t)(0x00);//second
   RTC->TR = rtc_time;
******************************************************************************/
#include "rtc.h"
#include <stdio.h>

RTC_DateTypeDef RTC_DateStructure;
RTC_TimeTypeDef RTC_TimeStructure;
__IO uint8_t showtime[50] = {0};
__IO uint8_t showdate[50] = {0};

void LEDInit(void)
{
	//LED2-PA5
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;  //打开Port A时钟
	GPIOA->MODER &= (~GPIO_MODER_MODER5);
	GPIOA->MODER |=GPIO_MODER_MODER5_0; //PA5输出
	GPIOA->OTYPER &= (~GPIO_OTYPER_OT_5); //PA5推挽输出
	//GPIOA->PUPDR &= (~GPIO_PUPDR_PUPDR5);
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPDR5_0; //PA5 PULL-UP
}

int main(void)
{  
   /* Initialize LEDs */
   LEDInit();
   /* Configure RTC */
   RTC_Config();
   
	while(1)
	{
      RTC_TimeStructure=RTC_GetTime();
      RTC_DateStructure=RTC_GetDate();
      
      /* Display time Format : hh:mm:ss */
      sprintf((char*)showtime,"%.2d:%.2d:%.2d",RTC_TimeStructure.RTC_Hours, RTC_TimeStructure.RTC_Minutes, RTC_TimeStructure.RTC_Seconds);
      /* Display date Format : mm-dd-yy */
      sprintf((char*)showdate,"%.2d-%.2d-%.2d",RTC_DateStructure.RTC_Month, RTC_DateStructure.RTC_Date, 2000 + RTC_DateStructure.RTC_Year);         
	}
}

