/*
* ssExecutor test. Switch Function Example
*/

#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

uint8_t flag = true; // switch function flag

void executeMe(){ // first function
  Serial.println("I'm executed!"); 
  flag = !flag;
}//executeMe

void meToo(){ // second function
  Serial.println("Me too!"); 
  flag = !flag;
}//executeMe

ssExecutor execObj = ssExecutor(EXEC_DELAY_MS);

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}


void loop() {
  if(flag) execObj.exec(executeMe);  
    else execObj.exec(meToo);    
}

