#ifndef STRAIGHT_ENEMY_H
#define STRAIGHT_ENEMY_H

#include "Enemy.h"

class StraightEnemy : public Enemy {
public:
    StraightEnemy();
    void calculateMovement(float deltaTime) override;
    void render(Renderer& renderer) override;
};

#endif // STRAIGHT_ENEMY_H