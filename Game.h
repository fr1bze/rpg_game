#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include "Player.h"
#include "Renderer.h"
#include "LevelGenerator.h"
#include "CollisionSystem.h"
#include "ScoreSystem.h"
#include "Enemy.h"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void processInput();
    void update(float deltaTime);
    void render();
    void initialize();
    void shutdown();

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;
    std::unique_ptr<LevelGenerator> m_levelGenerator;
    std::unique_ptr<ScoreSystem> m_scoreSystem;
    bool m_isRunning;
    Uint32 m_lastEnemySpawnTime = 0;
};

#endif // GAME_H