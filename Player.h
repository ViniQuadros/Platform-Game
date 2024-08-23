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
	void collision(sf::FloatRect block);

private:
	sf::RectangleShape player;

	sf::Vector2f velocity;
	float speed;
	sf::Vector2f size;

	const float maxY = 400.0f;
	const sf::Vector2f gravity = sf::Vector2f(0.f, 5.f);
	bool onAir;
};

