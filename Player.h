#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SDL3/SDL.h>
#include <memory>

class Renderer;

class Player : public Entity {
public:
    Player();

    void update(float deltaTime) override;
    void render(Renderer& renderer) override;

    void move(const Vector2f& direction);
    [[nodiscard]] const SDL_FRect& getBoxRect() const { return m_boxRect; }

private:
    float m_speed;
    SDL_FRect m_boxRect;
};

#endif // PLAYER_H