# ssExecutor

This library is designed to execute code at specified intervals.

## Table of contents
* [Public methods](#Public-methods)
  * [Constructors](#Constructors)
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
|delay_mp|`uint32_t`|The delay between executions in milliseconds. **Default: `0`**|
|func|`void (*ptr)(void)`|Pointer to the function to execute. **Default: `NULL`**|

## Usage examples


## History

* 07.04.2025 - First stable release