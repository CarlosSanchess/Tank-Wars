#include "gameController.h"

static int backgroundFlag = 0;

void resetGame(Arena *arena) {
    freeTank(arena->tank);
    freeEnemyTank(arena->enemyTank);
    arena->tank = createTank(145, 410, 0, 1, 3);
    arena->enemyTank = createEnemyTank(970, 410, 0, 1, 3);
    arena->crosshair->crossHair = 0;
    arena->crosshair->canBuild = true;
    arena->numBuilts = 0;
    arena->numBullets = 0;
}

int changeToMenu(State* gameState, Arena* arena){

    if (*gameState == inGame) {
            *gameState = inMenu;
            backgroundFlag = 0;
            resetGame(arena);
            drawMenuBackGround();
            return 0;
        } else if (*gameState == inMenu) {
            return 1;
        }

    return 0;
}

int changeBackground(){
    if(backgroundFlag == 0){
        drawGameBackGround();
        backgroundFlag = 1;
            printf("desenhou jogo");

    }
    return 0;
}

