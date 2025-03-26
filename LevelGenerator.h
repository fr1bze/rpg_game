#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "Enemy.h"
#include "Vector2f.h"
#include <vector>
#include <memory>
#include <random>

class LevelGenerator {
public:
    LevelGenerator();

    void generateEnemies(std::vector<std::unique_ptr<Enemy>>& enemies,
                         const Vector2f& playerPos,
                         int currentScore);

private:
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<> m_typeDist;
    std::uniform_real_distribution<float> m_posDist;

    EnemyType getRandomEnemyType();
    Vector2f getRandomPosition(const Vector2f& playerPos);
};

#endif // LEVEL_GENERATOR_H