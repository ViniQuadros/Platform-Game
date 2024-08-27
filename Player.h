#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(sf::Vector2f size, float speed);

	void render(sf::RenderWindow& window);
	void update(float dt);
	void inputHandle(float dt);
	void killHeight();
	void restart();
	void collision(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& blocksFloor);
	sf::FloatRect playerBounds();

protected:
	sf::Vector2f velocity;
	float speed;

private:
	sf::RectangleShape player;

	sf::Vector2f initialPosition;
	sf::Vector2f size;
	sf::View viewport;

	const float maxY = 400.0f;
	const sf::Vector2f gravity = sf::Vector2f(0.f, 10.f);
	bool isOnAir;
	bool isOnAnyBlock;
};

