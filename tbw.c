#include "tbw.h"

int main(void)
{
  
  USART_init();		//for communication purposes
  sbi(DDRB,PB0);
  sbi(PORTB,PB0);
  
  volatile uint16_t sensor_digital_value=0;
  init_servo();		//initialize servo with its pin ,mode ,ICR1 and cycles per seconds
  init_sensor();	  //initialize sensor and adjust ADC process
  //putting min and maximum degrees:
  float min_deg=2000.0;	//at zero sensor_digital_valueue from ADC
  float max_deg=4000.0;	//at 1023 sensor_digital_valueue from ADC
  float Duty_cycle=(max_deg-min_deg)/1023.0;	//by cross multiplying
  
  char int_buffer[10];    //for integer to string function which needed in communication
  
  while (1)
  {
	  USART_putstring("sensor_read:   ");
	  sensor_digital_value=adc_read(0);
	  OCR1A=(ICR1-2000)-(sensor_digital_value*Duty_cycle);
	  itoa(sensor_digital_value,int_buffer,10);
	  USART_putstring(int_buffer);
	  // _delay_ms(100);
	  // OCR1A=ICR1-2000;  //zero degree one degree equal 11 sensor_digital_valueue in ocr1a	  
	}

	return 0;
}


/*ISR(ADC_vect)
{
	//getting sensor read:
	uint8_t low_adc=ADCL;
	sensor_read= (ADCH<<8)|low_adc;
	//sensor_digital_sensor_digital_value=(float) (sensor_read/1024)*100;
	//restart AD conversion
	sbi(ADCSRA,ADSC);

}
*/