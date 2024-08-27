#include "Level.h"

Level::Level() :
	floorBlock(sf::Vector2f(400.0f, 550.0f), sf::Vector2f(800.0f, 300.0f)),
	floorBlock2(sf::Vector2f(1200.0f, 550.0f), sf::Vector2f(600.0f, 300.0f)),
	floorBlock3(sf::Vector2f(1250.0f, 450.0f), sf::Vector2f(300.0f, 300.0f)),
	platform1(sf::Vector2f(700.0f, 300.0f), sf::Vector2f(150.0f, 20.0f)),
	platform2(sf::Vector2f(500.0f, 250.0f), sf::Vector2f(120.0f, 20.0f)),
	enemy1(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(1000.0f, 390.0f), 60.0f)
{
	blocksTop = { floorBlock.getBoundings(), floorBlock2.getBoundings(), floorBlock3.getBoundings(), platform1.getBoundings(), platform2.getBoundings() };
	blocksFloor = { floorBlock.getBoundings(), floorBlock2.getBoundings(), floorBlock3.getBoundings() };
}

void Level::render(sf::RenderWindow& window)
{
	floorBlock.render(window);
	floorBlock2.render(window);
	floorBlock3.render(window);
	platform1.render(window);
	platform2.render(window);

	enemy1.render(window);
}

void Level::playerCollision(Player& player)
{
	player.collision(blocksTop, blocksFloor);
	enemy1.kill(player);
}

void Level::update(float dt)
{
	enemy1.movement(blocksTop, dt);
}
