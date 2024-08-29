#pragma once

#include "Player.h"

class Enemy
{
public:
	Enemy(sf::Vector2f size, sf::Vector2f position, float speed);

	void render(sf::RenderWindow& window);
	void kill(Player& player);
	void movement(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& invisibleBlocks, float dt);

private:
	sf::RectangleShape enemy;

	sf::Vector2f velocity;
	float speed;
};


