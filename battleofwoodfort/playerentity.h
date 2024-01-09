#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include <rt2d/entity.h>

class PlayerEntity : public Entity
{
    public:
    //constructor
    PlayerEntity();
    //destructor
    virtual ~PlayerEntity();

    void update(float deltaTime) override;

    private:
    //add your private declarations
};

#endif