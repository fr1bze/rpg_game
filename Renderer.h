#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <memory>
#include "Vector2f.h"

class Renderer {
public:
    explicit Renderer(SDL_Window* window);
    ~Renderer();

    void clear();
    void present();
    void drawRect(float x, float y, float w, float h, const SDL_Color& color);
    void drawRectOutline(float x, float y, float w, float h, const SDL_Color& color);

private:
    SDL_Renderer* m_renderer;
};

#endif // RENDERER_H