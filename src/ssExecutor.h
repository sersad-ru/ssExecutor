/*
ssExecutor library
(c)2025 by Sergey Sadovnikov (sersad@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <www.gnu.org/licenses/>.
*/
#pragma once
#include <Arduino.h>

// Прототип исполняемого кода
typedef void (*ssPayload)(void);

class ssExecutor {
  public:
    ssExecutor(const uint32_t delay_ms = 0, const ssPayload func = NULL) {setDelay(delay_ms);_func = func;};
    ssExecutor(const ssPayload func) : ssExecutor(0, func) {};

    void exec(uint32_t delay_ms = 0, ssPayload func = NULL);
    void exec(const ssPayload func){exec(0, func);};

    void setDelay(const uint32_t delay_ms){_delay_ms = delay_ms;};
    uint32_t getDelay(){return _delay_ms;};

  protected:
    virtual void run(){};
    
  private:
    uint32_t _delay_ms = 0;
    ssPayload _func = NULL;
};//class