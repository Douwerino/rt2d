#ifndef BACKGROUNDENTITY_H
#define BACKGROUNDENTITY_H

#include <rt2d/entity.h>

class BackGroundEntity : public Entity
{
    public:
    //constructor
    BackGroundEntity();
    //destructor
    virtual ~BackGroundEntity();

    void update(float deltaTime) override;

    private:
    //add your private declarations
};

#endif