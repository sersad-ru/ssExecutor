#include <Arduino.h>
#include <ssExecutor.h>

#define FOO_DELAY_MS 2000

// Class version
class Foo : public ssExecutor {
  public:
    Foo() : ssExecutor(FOO_DELAY_MS){};
    virtual void run(){Serial.println("Foo class");};
};

Foo barObj = Foo();

// Lambda version

// Direct version

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}


void loop() {
  barObj.exec();
  barObj.exec(4000); // Delay overload
}
