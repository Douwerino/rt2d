#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <deque>
#include <rt2d/timer.h>
#include "projects/demo/basicentity.h"
#include "scene.h"

#include "backgroundentity.h"

class gamescene : public Scene 
{
    public: 
    gamescene();
    virtual ~gamescene();
    virtual void update(float delataTime);

    private:
    backgroundentity* BackGroundEntity;
    Timer t;
};

#endif
