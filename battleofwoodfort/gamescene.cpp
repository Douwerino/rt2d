#include <fstream>
#include <sstream>

#include "gamescene.h"

gamescene::gamescene() : Scene(){ 
    
    shootTimer.start();
    //timer

    backgroundentity = new BackGroundEntity();
    backgroundentity->scale = Point2(3, 1.5);
    backgroundentity->position = Point2(SWIDTH / 2, SHEIGHT / 2);

    this->addChild(backgroundentity);
    
    playerentity = new PlayerEntity();
    playerentity->position = Point2(SWIDTH / 2, SHEIGHT / 1.06);

    this->addChild(playerentity);

    enemyentity = new EnemyEntity();
    enemyentity->position = Point2(SWIDTH / 2, SHEIGHT / 5);

    this->addChild(enemyentity);

}

gamescene::~gamescene(){
    
    this->removeChild(backgroundentity);

    delete backgroundentity;

    this->removeChild(playerentity);

    delete playerentity;

    this->removeChild(enemyentity);

    delete enemyentity;

}

void gamescene::update (float deltaTime){

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
    
    if (input()->getKeyUp(KeyCode::Space)) {
        if (shootTimer.seconds() >= arrowCooldown) {
            ArrowEntity* arrowentity = new ArrowEntity();
            arrowentity->scale = Point2(0.5, 1);
            this->addChild(arrowentity);
            quiver.push_back(arrowentity);
            quiver[quiver.size() - 1]->position = playerentity->position;

            shootTimer.start();
        }
    
    }

    int i = 0; 
    while (i < quiver.size()) {
        quiver[i]->position.y -= 500 * deltaTime;
           
        if (checkArrowEnemyCollision(quiver[i], enemyentity)) {
            // Handle enemy hit logic here (e.g., reduce health, play hit animation, etc.)

            // Remove the arrow from the scene
            this->removeChild(quiver[i]);

            // Delete the arrow entity to free the memory
            delete quiver[i];

            // Remove the arrow from the quiver vector
            quiver.erase(quiver.begin() + i);

            // Handle enemy death logic here (e.g., play death animation, respawn, etc.)
            // For simplicity, I'm just removing the enemy from the scene and deleting it
            this->removeChild(enemyentity);
            delete enemyentity;

            // Create a new enemy entity (respawn)
            enemyentity = new EnemyEntity();
            enemyentity->position = Point2(SWIDTH / 2, SHEIGHT / 5);
            this->addChild(enemyentity);

            // Break out of the loop, as we've handled the collision
            break;

        }
            // Check if the arrow has reached the top of the screen
        else if (quiver[i]->position.y < -25) {
                // Remove the arrow from the scene
                this->removeChild(quiver[i]);

                // Delete the arrow entity to free the memory
                delete quiver[i];

                // Remove the arrow from the quiver vector
                quiver.erase(quiver.begin() + i);
        }
        else {
            i++;
        }
    }
}