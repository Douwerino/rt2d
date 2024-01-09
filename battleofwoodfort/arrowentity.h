#ifndef ARROWENTITY_H
#define ARROWENTITY_H

#include <rt2d/entity.h>

class ArrowEntity : public Entity
{
    public:
    //constructor
    ArrowEntity();
    //destructor
    virtual ~ArrowEntity();

    void update(float deltaTime) override;

    bool alive;

    private:
    //add your private declarations
};

#endif