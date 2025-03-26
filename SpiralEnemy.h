#ifndef SPIRAL_ENEMY_H
#define SPIRAL_ENEMY_H

#include "Enemy.h"

class SpiralEnemy : public Enemy {
public:
    SpiralEnemy();
    void calculateMovement(float deltaTime) override;
    void render(Renderer& renderer) override;

private:
    float m_spiralRadius = 50.0f;
    float m_spiralSpeed = 3.0f;
    float m_currentAngle = 0.0f;
};

#endif // SPIRAL_ENEMY_H