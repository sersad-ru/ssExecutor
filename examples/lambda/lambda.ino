/*
 * ssExecutor test. Lambda Example
 */

#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

ssExecutor execObj = ssExecutor(EXEC_DELAY_MS, [](){
  Serial.println("I'am executed!");
});

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}


void loop() {
  execObj.exec();
}
