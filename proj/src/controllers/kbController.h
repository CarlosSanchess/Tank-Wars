#ifndef __KBController__
#define __KBController__

#include "../dev_interface/devices/timer_kbc_mouse/kbc.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "kbController.c"

extern uint8_t scanCode;

int handleInterruptKBC(State *gameState, Menu *menu);


#endif 
