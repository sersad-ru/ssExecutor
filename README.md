# ssExecutor

This library is designed to execute code at specified intervals.

## Table of contents
* [Public methods](#Public-methods)
  * [Constructors](#Constructors)
  * [Executors](#Executors)
  * [Getters and Setters](#Getters-and-Setters)
  * [Virtual payload method](#Virtual-payload-method)
* [Usage examples](#Usage-examples)
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


## History

* 07.04.2025 - First stable release