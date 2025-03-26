#include "Player.h"
#include "Renderer.h"

Player::Player() : m_speed(300.0f) {
    m_position = {400.0f, 300.0f};
    m_size = {30.0f, 30.0f};
    m_color = {0, 255, 0, 255};

    m_boxRect = {
            m_position.x + m_size.x,
            m_position.y - 10.0f,
            40.0f,
            50.0f
    };
}

void Player::update(float deltaTime) {
    m_boxRect.x = m_position.x + m_size.x;
    m_boxRect.y = m_position.y - 10.0f;
}

void Player::render(Renderer& renderer) {
    renderer.drawRect(m_position.x, m_position.y, m_size.x, m_size.y, m_color);
    renderer.drawRectOutline(m_boxRect.x, m_boxRect.y, m_boxRect.w, m_boxRect.h, {255, 255, 0, 255});
}

void Player::move(const Vector2f& direction) {
    m_position.x += direction.x * m_speed;
    m_position.y += direction.y * m_speed;

    m_position.x = std::fmax(0.0f, std::min(m_position.x, 800.0f - m_size.x));
    m_position.y = std::fmax(0.0f, std::min(m_position.y, 600.0f - m_size.y));
}