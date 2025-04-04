/*
* ssExecutor test. Inplace Execution Example
*/

#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}


void loop() {
  static ssExecutor execObj = ssExecutor();
  execObj.exec(EXEC_DELAY_MS, [](){
    Serial.println("I'am executed!");
  });
}
