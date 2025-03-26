#include "ZigzagEnemy.h"

ZigzagEnemy::ZigzagEnemy() {
    m_type = EnemyType::Zigzag;
    m_color = {0, 0, 255, 255};
    m_size = {20.0f, 20.0f};
}

void ZigzagEnemy::calculateMovement(float deltaTime) {
    m_currentAngle += m_zigzagFrequency * deltaTime;

    Vector2f toTarget = m_target - m_position;
    float distance = toTarget.length();

    if (distance > 0) {
        Vector2f mainDirection = toTarget.normalized();
        Vector2f perpendicular = {-mainDirection.y, mainDirection.x};

        Vector2f zigzag = perpendicular * sin(m_currentAngle) * m_zigzagAmplitude;
        m_position += (mainDirection + zigzag) * m_speed * deltaTime;
    }
}

void ZigzagEnemy::render(Renderer& renderer) {
    renderer.drawRect(m_position.x, m_position.y, m_size.x, m_size.y, m_color);
}
