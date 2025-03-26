#ifndef ZIGZAG_ENEMY_H
#define ZIGZAG_ENEMY_H

#include "Enemy.h"

class ZigzagEnemy : public Enemy {
public:
    ZigzagEnemy();
    void calculateMovement(float deltaTime) override;
    void render(Renderer& renderer) override;

private:
    float m_zigzagFrequency = 5.0f;
    float m_zigzagAmplitude = 1.0f;
    float m_currentAngle = 0.0f;
};

#endif // ZIGZAG_ENEMY_H