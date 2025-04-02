#include "ssExecutor.h"

void ssExecutor::exec(uint32_t delay_ms, const ssPayload func){
  if(!delay_ms) delay_ms = _delay_ms;
  static uint32_t last_action = millis();
  if((millis() - last_action) < delay_ms) return;
  last_action = millis();

  if(func) func();
  run();
}//exec
