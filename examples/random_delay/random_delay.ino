/*
 * ssExecutor test. Random Delay Example
 */

#include <Arduino.h>
#include <ssExecutor.h>

uint32_t rnd = 250; // use 250 ms for the first run

ssExecutor execObj = ssExecutor([](){
  Serial.println("I'm executed!"); 
  rnd = random(1, 21) * 250; // Prepare random delay from 250 to 5000 ms (step 250ms)
  Serial.print("Next in: ");
  Serial.print(rnd); 
  Serial.println(" ms");
});

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
  randomSeed(analogRead(0));
}


void loop() {  
  execObj.exec(rnd); // Use random delay from 250 to 5000 ms (step 250ms)
}
