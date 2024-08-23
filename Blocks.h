#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Blocks
{
public:
	Blocks(sf::Vector2f position, sf::Vector2f size);

	void render(sf::RenderWindow& window);
	sf::FloatRect getBoundings();

private:
	sf::RectangleShape block;
	sf::FloatRect blockBoundings;
};
