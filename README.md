# ssExecutor

This library is designed to execute code at specified intervals.

## Table of contents
* [Public methods](#Public-methods)
  * [Constructors](#Constructors)
  * [Executors](#Executors)
  * [Getters and Setters](#Getters-and-Setters)
  * [Virtual payload method](#Virtual-payload-method)
* [Usage examples](#Usage-examples)
  * [Child class](#Child-class)
  * [Function](#Function)
  * [Lambda](#Lambda)
  * [Inplace](#Inplace)
  * [Switch function](#Switch-function)
  * [Random delay](#Random-delay)
* [History](#History)

## Public methods

### Constructors

```cpp
ssExecutor(const uint32_t delay_ms = 0, const ssPayload func = NULL);
ssExecutor(const ssPayload func);
```

Creates the `ssExecutor` object and optionally setup base parameters.

|Prarm|Type|Description|
|:---:|:---|:---|
|delay_ms|`uint32_t`|The delay between executions in milliseconds. **Default: `0`**|
|func|`void (*ptr)(void)`|Pointer to the function to execute. **Default: `NULL`**|


### Executors

```cpp
void exec(uint32_t delay_ms = 0, ssPayload func = NULL);
void exec(const ssPayload func);
```

Runs the code if specified interval was passed since the last execution.

|Prarm|Type|Description|
|:---:|:---|:---|
|delay_ms|`uint32_t`|The delay between executions in milliseconds. **Default: `0`**|
|func|`void (*ptr)(void)`|Pointer to the function to execute. **Default: `NULL`**|


### Getters and Setters

```cpp
void setDelay(const uint32_t delay_ms);
uint32_t getDelay();   

void setLastAction(const uint32_t last_ms);
uint32_t getLastAction();
```

Gets and sets the delay between executions in milliseconds and gets/sets the last 
execution time.

|Prarm|Type|Description|
|:---:|:---|:---|
|delay_ms|`uint32_t`|The delay between executions in milliseconds.|


### Virtual payload method

```cpp
protected:
  virtual void run(){};
```

This method can be overridden in child classes. `ssExecutor` will call it if no payload
was specified in `constructor` or `exec`-method.


## Usage examples

### Child class

```cpp
#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

// Define the child class
class Foo : public ssExecutor {
  public:
    Foo() : ssExecutor(EXEC_DELAY_MS){}; // Call base class constructor and specify the execution delay
    void run() override {Serial.println("I'am executed!");}; // will be executed every EXEC_DELAY_MS miliseconds
};

Foo fooObj = Foo(); // Create the object

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}

void loop() {
  fooObj.exec();
}

```

Prints "I'am executed!" every 2 seconds to the console.


### Function

```cpp
#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

void executeMe(){ // will be executed every EXEC_DELAY_MS miliseconds
  Serial.println("I'am executed!"); 
}//executeMe

// Create ssExecutor object and specify execution delay and funcion to execute
ssExecutor execObj = ssExecutor(EXEC_DELAY_MS, executeMe); 

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}

void loop() {
  execObj.exec();  
}
```

Prints "I'am executed!" every 2 seconds to the console.


### Lambda

```cpp
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
```

Prints "I'am executed!" every 2 seconds to the console.


### Inplace

```cpp
#include <Arduino.h>
#include <ssExecutor.h>

#define EXEC_DELAY_MS 2000

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}

void loop() {
  static ssExecutor execObj = ssExecutor(); // Create static ssExecutor object
  execObj.exec(EXEC_DELAY_MS, [](){
    Serial.println("I'am executed!");
  });
}
```

Prints "I'am executed!" every 2 seconds to the console.


### Switch function

```cpp
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

// Create the ssExecutor object and specify execution delay
ssExecutor execObj = ssExecutor(EXEC_DELAY_MS);

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nssExecutor test.");
}

void loop() {
  if(flag) execObj.exec(executeMe);  
    else execObj.exec(meToo);    
}

```

Prints "I'am executed!". In 2 seconds prints "Me too". 
In 2 seconds prints "I'am executed!" again and so on.


### Random delay

```cpp
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
```

Prints "I'am executed! Next in xxx ms" with random delay.

## History

* 07.04.2025 - First stable release