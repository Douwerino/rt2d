#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <deque>
//#include <rt2d/timer.h>
#include "projects/demo/basicentity.h"
#include "scene.h"
#include "timer.h"

#include "backgroundentity.h"
#include "playerentity.h"
#include "arrowentity.h"
#include "enemyentity.h"
#include "pilarentity.h"


class gamescene : public Scene 
{
    public: 
    gamescene();
    virtual ~gamescene();
    virtual void update(float delataTime);

    private:
    BackGroundEntity* backgroundentity;
    PlayerEntity* playerentity;
    int lives = 3;
    EnemyEntity* enemyentity;
    std::vector<ArrowEntity*> quiver;

    float arrowCooldown = 1.0f; //2 second cooldown
    Timer shootTimer;
};

#endif
