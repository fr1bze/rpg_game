#include <algorithm>
#include "SpiralEnemy.h"

SpiralEnemy::SpiralEnemy() {
    m_type = EnemyType::Spiral;
    m_color = {255, 0, 255, 255};
    m_size = {20.0f, 20.0f};
}

void SpiralEnemy::calculateMovement(float deltaTime) {
    m_currentAngle += m_spiralSpeed * deltaTime;

    Vector2f toTarget = m_target - m_position;
    float distance = toTarget.length();

    if (distance > 0) {
        Vector2f mainDirection = toTarget.normalized();
        Vector2f perpendicular = {-mainDirection.y, mainDirection.x};

        Vector2f spiral = perpendicular * sin(m_currentAngle) * m_spiralRadius +
                          mainDirection * cos(m_currentAngle) * m_spiralRadius;

        m_position += (mainDirection + spiral) * m_speed * deltaTime;
        m_spiralRadius = std::fmax(0.0f, m_spiralRadius - deltaTime * 10.0f);
    }
}

void SpiralEnemy::render(Renderer& renderer) {
    renderer.drawRect(m_position.x, m_position.y, m_size.x, m_size.y, m_color);
}