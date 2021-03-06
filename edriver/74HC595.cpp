/*
file   : 74hc595.cpp
author : shentq
version: V1.0
date   : 2015/7/5

Copyright 2015 shentq. All Rights Reserved.

Copyright Notice
No part of this software may be used for any commercial activities by any form or means, without the prior written consent of shentq.

Disclaimer
This specification is preliminary and is subject to change at any time without notice. shentq assumes no responsibility for any errors contained herein.
*/

#include "74hc595.h"

_74hc595::_74hc595(GPIO* p_data_pin, GPIO* p_sck_pin,GPIO* p_rck_pin)
{
	data_pin 	= p_data_pin;
	sck_pin 	= p_sck_pin;
	rck_pin 	= p_rck_pin;
	

}
void _74hc595::begin()
{
	data_pin->mode(OUTPUT_PP);
	sck_pin->mode(OUTPUT_PP);
	rck_pin->mode(OUTPUT_PP);
}
void _74hc595::write(uint8_t* data,uint8_t data_length,uint8_t bit_oder)
{
	rck_pin->write(LOW);
	for(int i = 0; i < data_length; i++)
	shift_out(data_pin,sck_pin,bit_oder,data[i]);

}
void _74hc595::write(uint8_t data,uint8_t bit_oder)
{
	rck_pin->write(LOW);
	shift_out(data_pin,sck_pin,bit_oder,data);

}
void _74hc595::update()
{
  rck_pin->write(HIGH);

}


