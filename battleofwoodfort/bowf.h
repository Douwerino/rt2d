#ifndef BOWF_H
#define BOWF_H

#include <rt2d/scene.h>
#include <rt2d/canvas.h>

class Bowf : public Scene 
{
public:
    Bowf();
    virtual ~Bowf();

    virtual void update(float deltaTime);

    //Canvas battlescene = Canvas(4);

};


#endif /*BOWF_H*/
