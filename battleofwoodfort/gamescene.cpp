#include <fstream>
#include <sstream>

#include "gamescene.h"

gamescene::gamescene() : Scene()
{
    t.start();
    //timer

    backgroundentity = new BackGroundEntity();
    backgroundentity->scale = Point2(3, 1.5);
    backgroundentity->position = Point2(SWIDTH / 2, SHEIGHT / 2);
    //BackGroundEntity->scale == Point(SWIDTH / 512, SHEIGHT / 512);

    this->addChild(backgroundentity);
    
    playerentity = new PlayerEntity();
    playerentity->position = Point2(SWIDTH / 2, SHEIGHT / 1.06);
    //PlayerEntity->scale == Point(SWIDTH / 512, SHEIGHT / 512);

    this->addChild(playerentity);

}

gamescene::~gamescene()
{
    this->removeChild(backgroundentity);

    delete backgroundentity;

    this->removeChild(playerentity);

    delete playerentity;
}

void gamescene::update (float deltaTime)
{
    if (input()->getKeyUp(KeyCode::Space))
    {
        // if (shoottimer.seconds() > 0.8f) {
        //     PixelSprite b = player_arrow; // copy sprites etc
        //     b.position = player.position + Pointi(0, 2);
        //     player_arrow.push_back(b);
        //     shoottimer.start();
        // }

        

    }

    if (input()->getKey(KeyCode::Left)) {
		playerentity->position.x -= 250*deltaTime;
	}
	if (input()->getKey(KeyCode::Right)) {
        playerentity->position.x += 250*deltaTime;
	}

    if (playerentity->position.x > SWIDTH-1) {
        playerentity->position.x = SWIDTH -1;
    }
    if (playerentity->position.x < 1) {
        playerentity->position.x = 1;
    }
    
    if (input()->getKeyUp(KeyCode::Space)) 
    {
        ArrowEntity* arrowentity = new ArrowEntity();
        this->addChild(arrowentity);
        quiver.push_back(arrowentity);
        quiver[quiver.size() -1]->position = playerentity->position;
    }

    int i = 0; 
    while (i < quiver.size()) {
        quiver[i]->position.y--;
        
        i++;
    }
}