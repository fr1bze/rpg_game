#include "LevelGenerator.h"
#include "StraightEnemy.h"
#include "ZigzagEnemy.h"
#include "SpiralEnemy.h"

LevelGenerator::LevelGenerator() :
        m_gen(m_rd()),
        m_typeDist(0, 2),
        m_posDist(0.0f, 1.0f) {}

void LevelGenerator::generateEnemies(std::vector<std::unique_ptr<Enemy>>& enemies,
                                     const Vector2f& playerPos,
                                     int currentScore) {
    int spawnRate = std::max(1, 60 - currentScore / 10);

    if (rand() % spawnRate == 0) {
        EnemyType type = getRandomEnemyType();
        Vector2f position = getRandomPosition(playerPos);

        std::unique_ptr<Enemy> enemy;
        switch (type) {
            case EnemyType::Straight:
                enemy = std::make_unique<StraightEnemy>();
                break;
            case EnemyType::Zigzag:
                enemy = std::make_unique<ZigzagEnemy>();
                break;
            case EnemyType::Spiral:
                enemy = std::make_unique<SpiralEnemy>();
                break;
        }

        enemy->setPosition(position);
        enemy->setTarget(playerPos);
        enemy->setSpeed(100.0f + (currentScore / 10.0f));

        enemies.push_back(std::move(enemy));
    }
}

EnemyType LevelGenerator::getRandomEnemyType() {
    return static_cast<EnemyType>(m_typeDist(m_gen));
}

Vector2f LevelGenerator::getRandomPosition(const Vector2f& playerPos) {
    float angle = m_posDist(m_gen) * 2 * M_PI;
    float distance = 500.0f + m_posDist(m_gen) * 200.0f;

    return Vector2f(
            playerPos.x + cos(angle) * distance,
            playerPos.y + sin(angle) * distance
    );
}