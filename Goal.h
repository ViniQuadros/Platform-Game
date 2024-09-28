#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

class Goal
{
public:
	Goal();

	void render(sf::RenderWindow& window);
	void update(float dt);
	void win(Player& player);
	bool hasEnded();

private:
	sf::Texture texture;
	sf::Sprite sprite;

	float speed;
	bool end;

	sf::Vector2f velocity;
	sf::Clock clock;
};