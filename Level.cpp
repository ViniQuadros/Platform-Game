#include "Level.h"

Level::Level() :
	floorBlock(sf::Vector2f(400.0f, 550.0f), sf::Vector2f(800.0f, 300.0f)),
	platform1(sf::Vector2f(700.0f, 300.0f), sf::Vector2f(150.0f, 20.0f)),
	platform2(sf::Vector2f(500.0f, 250.0f), sf::Vector2f(120.0f, 20.0f))
{
	blocks = { floorBlock.getBoundings(), platform1.getBoundings(), platform2.getBoundings() };
}

void Level::render(sf::RenderWindow& window)
{
	floorBlock.render(window);
	platform1.render(window);
	platform2.render(window);
}

void Level::update(Player& player)
{
	player.collision(blocks);
}
