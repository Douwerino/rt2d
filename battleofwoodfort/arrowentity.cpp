#include "arrowentity.h"

ArrowEntity::ArrowEntity()
{
    this->addSprite("assets/Player.tga");
    
    this->sprite()->color = BLACK;

    this->alive = true;

}


ArrowEntity::~ArrowEntity()
{

}

void ArrowEntity::update(float deltaTime)
{
   // this->position.y -= deltaTime * 200;
}