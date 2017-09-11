#ifndef TBW_H_
#define TBW_H_
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <stdlib.h>
#include <avr/sleep.h>
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include "sensor.h"
#include "servo.h"
//#include "usart.h"
#define EVEN 0
#define ODD 1

#define sbi(reg,pin) reg|=_BV(pin)
#define cbi(reg,pin) reg&=~_BV(pin)
#define tbi(reg,pin) reg^=_BV(pin)
#define is_high(reg,pin) (((reg)&_BV(pin))==1)


#endif

