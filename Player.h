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
	void collision(const std::vector<sf::FloatRect>& blocks);
	void die();

private:
	sf::RectangleShape player;

	sf::Vector2f initialPosition;
	sf::Vector2f velocity;
	float speed;
	sf::Vector2f size;
	sf::View viewport;

	const float maxY = 410.0f;
	const sf::Vector2f gravity = sf::Vector2f(0.f, 10.f);
	bool isOnAir;
	bool isOnAnyBlock;
};

