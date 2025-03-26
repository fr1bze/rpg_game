#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2f.h"
#include <SDL3/SDL.h>

class Renderer;

class Entity {
public:
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render(Renderer& renderer) = 0;

    const Vector2f& getPosition() const { return m_position; }
    const Vector2f& getSize() const { return m_size; }
    void setPosition(const Vector2f& pos) { m_position = pos; }

protected:
    Vector2f m_position;
    Vector2f m_size;
    SDL_Color m_color;
};

#endif // ENTITY_H