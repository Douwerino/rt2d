#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H

#include <rt2d/entity.h>

class EnemyEntity : public Entity
{
    public:
    //constructor
       EnemyEntity();
    //destructor
    virtual ~EnemyEntity();

    void update(float deltaTime) override;

    private:
    //add your private declarations
};

#endif