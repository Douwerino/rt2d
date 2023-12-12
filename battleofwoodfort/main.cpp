#include <rt2d/core.h>
//#include "bowf.h"

#include "gamescene.h"


int main(void)
{
    Core core;

    Scene* Gamescene = new gamescene();
    while (Gamescene->isRunning()) 
    {
        core.run(Gamescene);
        core.showFrameRate(5);
    }
    delete Gamescene;
    return 0;

}
