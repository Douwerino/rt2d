#ifndef BACKGROUNDENTITY_H
#define BACKGROUNDENTITY_H

#include <rt2d/entity.h>

class backgroundentity : public Entity
{
    public:
    //constructor
    backgroundentity();
    //destructor
    virtual ~backgroundentity();

    virtual void update(float deltaTime);

    private:
    //add your private declarations
};

#endif