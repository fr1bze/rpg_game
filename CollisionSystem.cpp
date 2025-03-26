#include "CollisionSystem.h"

bool CollisionSystem::checkBoxCollision(const Player& player, const Enemy& enemy) {
    SDL_FRect box = player.getBoxRect();
    SDL_FRect enemyRect = {
            enemy.getPosition().x,
            enemy.getPosition().y,
            enemy.getSize().x,
            enemy.getSize().y
    };

    return SDL_HasRectIntersectionFloat(&box, &enemyRect);
}

bool CollisionSystem::checkPlayerCollision(const Player& player, const Enemy& enemy) {
    SDL_FRect playerRect = {
            player.getPosition().x,
            player.getPosition().y,
            player.getSize().x,
            player.getSize().y
    };

    SDL_FRect enemyRect = {
            enemy.getPosition().x,
            enemy.getPosition().y,
            enemy.getSize().x,
            enemy.getSize().y
    };

    return SDL_HasRectIntersectionFloat(&playerRect, &enemyRect);
}