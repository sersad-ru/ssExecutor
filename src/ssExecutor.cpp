#include "ssExecutor.h"

void ssExecutor::exec(uint32_t delay_ms, ssPayload func){
  if(!delay_ms) delay_ms = _delay_ms;
  if(delay_ms && ((millis() - _last_action) < delay_ms)) return;
  _last_action = millis();
  if(!func) func = _func;
  if(func) func();
  run();
}//exec
