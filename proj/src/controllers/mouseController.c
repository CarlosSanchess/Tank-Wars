#include "mouseController.h"


void print_double(double n, bool x) {

  char str[100];
  if(x){
    sprintf(str, "EM X:%f\n", n);
    printf("EM X:%s ", str);
  }else{
    sprintf(str, "EM Y:%f\n", n);
    printf("EM Y:%s\n ========================================= \n ", str);
  }

}

//TODO ERROR HANDLING
int handleInterruptMouse(State *gameState, Menu *menu, MouseInfo *mouseInfo){
    mouse_ih();
    mouse_packet();
    print_double(mouse_byte_packet.delta_x, true);
    print_double(mouse_byte_packet.delta_y, false);

  if(mouseInfo->mousePosition.x+mouse_byte_packet.delta_x < 0 && !mouse_byte_packet.x_ov){
    mouseInfo->mousePosition.x = 0;
  }
  else if(mouseInfo->mousePosition.x+mouse_byte_packet.delta_x > 1152 && !mouse_byte_packet.x_ov){
    mouseInfo->mousePosition.x = 1152;
  }
  else if(!mouse_byte_packet.x_ov){
    mouseInfo->mousePosition.x+=mouse_byte_packet.delta_x;
  }

  if(mouseInfo->mousePosition.y-mouse_byte_packet.delta_y < 0 && !mouse_byte_packet.y_ov){
    mouseInfo->mousePosition.y = 0;
  }
  else if(mouseInfo->mousePosition.y-mouse_byte_packet.delta_y > 864 && !mouse_byte_packet.y_ov){
    mouseInfo->mousePosition.y = 864;
  }
  else if(!mouse_byte_packet.y_ov){
    mouseInfo->mousePosition.y-=mouse_byte_packet.delta_y;
  }
    
    if((mouse_byte_packet.delta_x > 327 && mouse_byte_packet.delta_x < 823) && (mouse_byte_packet.delta_x > 590 && mouse_byte_packet.delta_x < 673)){
        menu->selected = 0;
        if(mouse_byte_packet.lb){
            if(menu->selected == 0){
                *gameState = inGame;
            }
        }
     }
    return 0;
}
