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
//#include "pilarentity.h"


class GameScene : public Scene 
{
    public: 
    GameScene();
    virtual ~GameScene();
    virtual void update(float deltaTime);

    private:
    BackGroundEntity* backgroundentity;
    PlayerEntity* playerentity;
    int lives = 3;
    EnemyEntity* enemyentity;
    float enemyRespawnCooldown = 5.0f;
    Timer respawnTimer;

    std::vector<ArrowEntity*> quiver;
    float arrowCooldown = 1.0f;
    Timer shootTimer;
    bool checkArrowEnemyCollision(ArrowEntity* arrow, EnemyEntity* enemy);

};

#endif
