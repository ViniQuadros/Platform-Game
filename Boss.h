#pragma once

#include "Enemy.h"

class Boss : public Enemy
{
public:
    Boss(sf::Vector2f size, sf::Vector2f position, float speed);

    void update(float dt, sf::Vector2f playerPosition);
    void render(sf::RenderWindow& window) override;
    void jumpAttack(sf::Vector2f playerPosition);
    void shootProjectiles(float dt);

private:
    void applyGravity(float dt);
    void resetJump();
    void handleJump(float dt);
    void chooseNextAttack();

    sf::RectangleShape boss;
    sf::Vector2f velocity;
    float speed;
    float gravity;
    int jumpCount;
    bool isJumping;
    sf::Vector2f initialPosition;
    sf::Vector2f targetPosition;

    enum AttackType { None, Jump, Shoot } currentAttack;
    std::vector<sf::CircleShape> projectiles;

    sf::Clock attackTimer;
    sf::Time attackInterval;
};
