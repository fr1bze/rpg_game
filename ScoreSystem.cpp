#include "ScoreSystem.h"

void ScoreSystem::addScore(int points) {
    m_score += points;
}

float ScoreSystem::getSpeedMultiplier() const {
    return 1.0f + (m_score / static_cast<float>(m_speedIncreaseThreshold));
}