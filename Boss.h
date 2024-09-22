#pragma once

#include "Enemy.h"

class Boss : public Enemy
{
public:
    Boss(sf::Vector2f size, sf::Vector2f position, float speed);

    void update(float dt);
    void render(sf::RenderWindow& window) override;
    void movement(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& invisibleBlocks, float dt) override;
    void jumpAttack(float dt);

private:
    bool canAttack;
    bool isOnAnyBlock;

    const sf::Vector2f gravity = sf::Vector2f(0.f, 60.f);
    const float maxY = 5000.0f;

    sf::Clock clock;
    float delay;
};
