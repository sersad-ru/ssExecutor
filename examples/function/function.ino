/*
* ssExecutor test. Function Example
*/

#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

void executeMe(){ // will be executed every EXEC_DELAY_MS miliseconds
  Serial.println("I'am executed!"); 
}//executeMe

ssExecutor execObj = ssExecutor(EXEC_DELAY_MS, executeMe);

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}


void loop() {
  execObj.exec();  
}
