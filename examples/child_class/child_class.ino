/*
 * ssExecutor test. Child Class Example
 */

#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

class Foo : public ssExecutor {
  public:
    Foo() : ssExecutor(EXEC_DELAY_MS){}; // Call base class constructor and specify the execution delay
    void run() override {Serial.println("I'am executed!");}; // will be executed every EXEC_DELAY_MS miliseconds
};

Foo fooObj = Foo();

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}


void loop() {
  fooObj.exec();
  //fooObj.exec(1500); // Delay override
}
