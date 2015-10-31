/*
file   : *.cpp
author : shentq
version: V1.0
date   : 2015/7/5

Copyright 2015 shentq. All Rights Reserved.
*/

//STM32 RUN IN eBox
#include "ebox.h"
#include "led.h"
#include "button.h"

#include "time-protocol.h"

#define PPS_PIN PA7
#define DATE_LED_PIN PC14
LED led(&PA6,&PA4,&PA5);
BUTTON btn(&PA0,1);

void pps_on()
{

	PPS_PIN.set();
}
void pps_off()
{
	PPS_PIN.reset();
}
void date_led_on()
{
	DATE_LED_PIN.set();

}
void date_led_off()
{
	DATE_LED_PIN.reset();
}
u8 y = 0;
void setup()
{
	ebox_init();

	PPS_PIN.mode(OUTPUT_PP);
	DATE_LED_PIN.mode(OUTPUT_PP);
	uart1.begin(115200);
	led.begin();
	btn.begin();
	date_time.begin(115200);

	date_led_on();
}
u8 buf[] = "301015214100";
uint32_t x;
u32 current_systick = 0;
int main(void)
{
	setup();
	while(1)
	{
		if(date_time.process() == 1)
		{
			led.show_date_time(date_time.date_time);
			current_systick = millis();
		}
		
		if(millis() - current_systick > 500)
			pps_off();
		else
			pps_on();

//		delay_ms(1);
//		pps_on();
//		date_led_on();
//		delay_ms(500);
//		pps_off();
////		date_led_off();
//		delay_ms(500);
//		led.show_time(buf);
//		led.show_date(buf);
//		delay_ms(1000);
//		btn.loop();
//		if(btn.click() == 1)
//			uart1.printf("btn click!\r\n");
	}


}




