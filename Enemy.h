#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Vector2f.h"
#include <SDL3/SDL.h>
#include "EnemyType.h"
#include "Renderer.h"

class Enemy : public Entity {
public:
    virtual ~Enemy() = default;

    void update(float deltaTime) override {
        calculateMovement(deltaTime);
    }
    virtual void calculateMovement(float deltaTime) = 0;

    void setTarget(const Vector2f& target) { m_target = target; }
    float getSpeed() const { return m_speed; }
    void setSpeed(float speed) { m_speed = speed; }

protected:
    float m_speed = 100.0f;
    Vector2f m_target;
    EnemyType m_type;
};

#endif // ENEMY_H