#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "Player.h"
#include "Enemy.h"
#include <SDL3/SDL.h>

class CollisionSystem {
public:
    static bool checkBoxCollision(const Player& player, const Enemy& enemy);
    static bool checkPlayerCollision(const Player& player, const Enemy& enemy);
};

#endif // COLLISION_SYSTEM_H