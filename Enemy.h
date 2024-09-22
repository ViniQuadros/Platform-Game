#pragma once

#include "Player.h"

class Enemy
{
public:
	Enemy(sf::Vector2f size, sf::Vector2f position, float speed);

	virtual void render(sf::RenderWindow& window);
	void kill(Player& player);
	virtual void movement(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& invisibleBlocks, float dt);

protected:
	sf::RectangleShape enemy;

	sf::Vector2f velocity;
	float speed;

private:

};


