#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H

class ScoreSystem {
public:
    void addScore(int points);
    int getScore() const { return m_score; }
    float getSpeedMultiplier() const;

private:
    int m_score = 0;
    const int m_speedIncreaseThreshold = 100;
};

#endif // SCORE_SYSTEM_H