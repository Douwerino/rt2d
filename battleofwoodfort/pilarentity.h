#ifndef PILARENTITY_H
#define PILARENTITY_H

#include <rt2d/entity.h>

class PilarEntity : public Entity
{
    public:
    //constructor
    PilarEntity();
    //destructor
    virtual ~PilarEntity();

    void update(float deltaTime) override;

    private:
    //add your private declarations
};

#endif