#include "StraightEnemy.h"

StraightEnemy::StraightEnemy() {
    m_type = EnemyType::Straight;
    m_color = {255, 0, 0, 255};
    m_size = {20.0f, 20.0f};
}

void StraightEnemy::calculateMovement(float deltaTime) {
    Vector2f direction = m_target - m_position;
    float distance = direction.length();

    if (distance > 0) {
        direction = direction.normalized();
        m_position += direction * m_speed * deltaTime;
    }
}

void StraightEnemy::render(Renderer& renderer) {
    renderer.drawRect(m_position.x, m_position.y, m_size.x, m_size.y, m_color);
}