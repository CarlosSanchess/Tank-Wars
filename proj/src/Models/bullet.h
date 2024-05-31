#ifndef __BULLET__
#define __BULLET__

#include "Position.h"
#include "Hitbox.h"
#include "dev_interface/devices/video_gr.h"

#define BULLET_SPEED 5
#define BULLET_WIDTH 60
#define BULLET_HEIGHT 60

#define PLAYER 1
#define ENEMY 2

typedef struct{
    position position;
    int speed;
    uint8_t origin;
}bullet;


bullet* createBullet(position pos, int speed, uint8_t origin);
bullet** removeBulletFromBullets(bullet** bullets, size_t numBullets, size_t index);
void freebullet(bullet* b);
void createBulletHitbox(bullet* b, Hitbox* Hitbox);

#endif

