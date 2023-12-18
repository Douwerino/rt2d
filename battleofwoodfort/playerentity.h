#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include <rt2d/entity.h>

class playerentity : public Entity
{
    public:
    //constructor
    playerentity();
    //destructor
    virtual ~playerentity();

    virtual void update(float deltaTime);

    private:
    //add your private declarations
};

#endif