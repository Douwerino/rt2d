#include <fstream>
#include <sstream>

#include "gamescene.h"

gamescene::gamescene() : Scene() {
    
    shootTimer.start();
    respawnTimer.start();
    respawnTimer.pause();
    //timers

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

    //delete enemyentity;

}

bool gamescene::checkArrowEnemyCollision(ArrowEntity* arrow, EnemyEntity* enemy) {
    // Assuming a simple circular collision check based on positions
    float arrowRadius = 5.0;//0.25;     // Adjust the arrow radius based on your entity size
    float enemyRadius = 5.0;      // Adjust the enemy radius based on your entity size

    // Calculate the distance between the centers of the arrow and the enemy
    float distance = std::sqrt(std::pow(arrow->position.x - enemy->position.x, 2) +
        std::pow(arrow->position.y - enemy->position.y, 2));

    // Check if the distance is less than the sum of their radii
    return distance < (arrowRadius + enemyRadius);
}

void gamescene::update(float deltaTime) {

    if (input()->getKey(KeyCode::Left)) {
		playerentity->position.x -= 250*deltaTime;
	}
	if (input()->getKey(KeyCode::Right)) {
        playerentity->position.x += 250*deltaTime;
	}

    if (playerentity->position.x > SWIDTH - 1) {
        playerentity->position.x = SWIDTH - 1;
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

            // Remove the arrow from the scene
            this->removeChild(quiver[i]);
            delete quiver[i];

            // Remove the arrow from the quiver vector
            quiver.erase(quiver.begin() + i);

            this->removeChild(enemyentity);
            delete enemyentity;

            // Create a new enemy entity
            enemyentity = new EnemyEntity();
            enemyentity->position = Point2(SWIDTH / 2, SHEIGHT / 5);
            this->addChild(enemyentity);

            //enemy respawn timer
            //respawnTimer.start(enemyRespawnCooldown);//enemyRespawnCooldown

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
    // Check if the respawn timer is active
    if (respawnTimer.paused()) {
        // Check if the respawn timer has elapsed
        if (respawnTimer.seconds() >= enemyRespawnCooldown) {
            // Finish respawning
            respawnTimer.stop();

            // Create a new enemy entity
            enemyentity = new EnemyEntity();
            enemyentity->position = Point2(SWIDTH / 2, SHEIGHT / 5);
            this->addChild(enemyentity);
        }
        else {
            // Enemy is still respawning, update timer and skip  the rest of the update logic
            respawnTimer.unpause();
            respawnTimer.seconds();
            respawnTimer.pause(); //d(respawnTimer.seconds() + deltaTime >= enemyRespawnCooldown);
            return;
        }
    }


    //t200.start();


}

