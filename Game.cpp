#include "Game.h"
#include <SDL3/SDL.h>
#include <iostream>

Game::Game() : m_window(nullptr, SDL_DestroyWindow), m_isRunning(false) {
    initialize();
}

Game::~Game() {
    shutdown();
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL init failed: " << SDL_GetError() << std::endl;
        return;
    }

    m_window.reset(SDL_CreateWindow("Box Catcher Game", 800, 600, SDL_WINDOW_OPENGL));
    if (!m_window) {
        std::cerr << "window creation failed: " << SDL_GetError() << std::endl;
        return;
    }

    m_renderer = std::make_unique<Renderer>(m_window.get());
    m_player = std::make_unique<Player>();
    m_levelGenerator = std::make_unique<LevelGenerator>();
    m_scoreSystem = std::make_unique<ScoreSystem>();

    m_isRunning = true;
}

void Game::shutdown() {
    m_renderer.reset();
    m_window.reset();
    SDL_Quit();
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();

    while (m_isRunning) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        processInput();
        update(deltaTime);
        render();
    }
}

void Game::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
    }

    const auto* keyboardState = reinterpret_cast<const Uint8 *>(SDL_GetKeyboardState(nullptr));
    Vector2f direction(0.0f, 0.0f);

    if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_UP]) {
        direction.y -= 1.0f;
    }
    if (keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_DOWN]) {
        direction.y += 1.0f;
    }
    if (keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_LEFT]) {
        direction.x -= 1.0f;
    }
    if (keyboardState[SDL_SCANCODE_D] || keyboardState[SDL_SCANCODE_RIGHT]) {
        direction.x += 1.0f;
    }

    if (direction.x != 0.0f || direction.y != 0.0f) {
        m_player->move(direction.normalized());
    }
}

void Game::update(float deltaTime) {
    m_levelGenerator->generateEnemies(m_enemies, m_player->getPosition(), m_scoreSystem->getScore());

    for (auto it = m_enemies.begin(); it != m_enemies.end(); ) {
        (*it)->update(deltaTime);

        if (CollisionSystem::checkBoxCollision(*m_player, **it)) {
            m_scoreSystem->addScore(10);
            it = m_enemies.erase(it);
        }
        else if (CollisionSystem::checkPlayerCollision(*m_player, **it)) {
            m_isRunning = false;
            std::cout << "Game Over! Score: " << m_scoreSystem->getScore() << std::endl;
            break;
        }
        else {
            ++it;
        }
    }
}

void Game::render() {
    m_renderer->clear();
    m_player->render(*m_renderer);

    for (auto& enemy : m_enemies) {
        enemy->render(*m_renderer);
    }
    m_renderer->present();
}