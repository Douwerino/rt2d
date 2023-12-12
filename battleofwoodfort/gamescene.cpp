#include <fstream>
#include <sstream>

#include "gamescene.h"

int lives = 5;
bool isdead = false;






gamescene::gamescene() : Scene()
{
    t.start();
    //timer

    BackGroundEntity = new backgroundentity();
    BackGroundEntity->position = Point2(SWIDTH / 2, SHEIGHT / 2);

    this->addChild(BackGroundEntity);
}

gamescene::~gamescene()
{
    this->removeChild(BackGroundEntity);

    delete BackGroundEntity;
}

void gamescene::update (float deltaTime)
{
    
}