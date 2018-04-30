#include "DS1803.h"
#include <Wire.h>

/* Create an instance of the class
   0x28 is the address of the DS1803
   with three pin grounded. */
DS1803 pot(0x28);
int val = 128;

void setup() {
  //Begin serial connection at 9600 baud
  Serial.begin(9600) ;
}

void loop() {
  //Serial.println("Valor para pot0 [0-255]: ");
  
  while(Serial.available() == 0){
    ;
  }
  
  val = Serial.parseInt(); //Leer un entero por serial
  if ((val > 0) and (val < 256))
  {
	  //Set the first potentiometer at 200
  	pot.setPot(val,0);
    Serial.print("Valor para pot0: ");
	  Serial.println(val);
	}

  while(Serial.available() == 0) {
    ;
  }
  
  val = Serial.parseInt(); //Leer un entero por serial
  if ((val > 0) and (val < 256))
  {
	  //Set the first potentiometer at 200
    Serial.print("Valor para pot1: ");
	  pot.setPot(val,1);
	  Serial.println(val);
	}
  	//Read the values saved on the DS1803
  	int8_t *value=pot.getValue();
  	Serial.println(value[0],DEC);
  	Serial.println(value[1],DEC);
}


