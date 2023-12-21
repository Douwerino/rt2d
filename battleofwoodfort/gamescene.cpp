#include <fstream>
#include <sstream>

#include "gamescene.h"





gamescene::gamescene() : Scene()
{
    t.start();
    //timer

    BackGroundEntity = new backgroundentity();
    BackGroundEntity->position = Point2(SWIDTH / 2, SHEIGHT / 2);
    //BackGroundEntity->scale == Point(SWIDTH / 512, SHEIGHT / 512);

    this->addChild(BackGroundEntity);
    
    PlayerEntity = new playerentity();
    PlayerEntity->position = Point2(SWIDTH / 2, SHEIGHT / 1.24);
    //PlayerEntity->scale == Point(SWIDTH / 512, SHEIGHT / 512);

    this->addChild(PlayerEntity);
}

gamescene::~gamescene()
{
    this->removeChild(BackGroundEntity);

    delete BackGroundEntity;

    this->removeChild(PlayerEntity);

    delete PlayerEntity;
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
		PlayerEntity->position.x -= 250*deltaTime;
	}
	if (input()->getKey(KeyCode::Right)) {
		PlayerEntity->position.x += 250*deltaTime;
	}
    //Add deltaTime

}