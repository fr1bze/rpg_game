#include "Renderer.h"

Renderer::Renderer(SDL_Window* window) {
    m_renderer = SDL_CreateRenderer(window, nullptr);
    if (!m_renderer) {
        throw std::exception();
    }
}

Renderer::~Renderer() {
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

void Renderer::present() {
    SDL_RenderPresent(m_renderer);
}

void Renderer::drawRect(float x, float y, float w, float h, const SDL_Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_FRect rect = {x, y, w, h};
    SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::drawRectOutline(float x, float y, float w, float h, const SDL_Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_FRect rect = {x, y, w, h};
    SDL_RenderRect(m_renderer, &rect);
}