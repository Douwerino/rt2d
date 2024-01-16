#include "enemyentity.h"

EnemyEntity::EnemyEntity() : Entity()
{
    this->addSprite("assets/Player.tga");
    this->sprite()->color = RED;
}

EnemyEntity::~EnemyEntity()
{

}

void EnemyEntity::update(float deltaTime)
{
    
}
