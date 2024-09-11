#include "Level.h"

Level::Level() :
	floorBlock(sf::Vector2f(400.0f, 550.0f), sf::Vector2f(800.0f, 300.0f)),
	floorBlock2(sf::Vector2f(1200.0f, 550.0f), sf::Vector2f(600.0f, 300.0f)),
	floorBlock3(sf::Vector2f(1250.0f, 450.0f), sf::Vector2f(300.0f, 300.0f)),
	floorBlock4(sf::Vector2f(1900.0f, 550.0f), sf::Vector2f(400.0f, 300.0f)),
	floorBlock5(sf::Vector2f(2500.0f, 550.0f), sf::Vector2f(700.0f, 300.0f)),

	platform1(sf::Vector2f(700.0f, 300.0f), sf::Vector2f(150.0f, 20.0f)),
	platform2(sf::Vector2f(1000.0f, 250.0f), sf::Vector2f(120.0f, 20.0f)),
	platform3(sf::Vector2f(2300.0f, 280.0f), sf::Vector2f(150.0f, 20.0f)),

	invBlock1(sf::Vector2f(890.0f, 400.0f), sf::Vector2f(20.0f, 50.0f)),
	invBlock2(sf::Vector2f(930.0f, 230.0f), sf::Vector2f(20.0f, 50.0f)),
	invBlock3(sf::Vector2f(1070.0f, 230.0f), sf::Vector2f(20.0f, 50.0f)),
	invBlock4(sf::Vector2f(2140.0f, 400.0f), sf::Vector2f(20.0f, 50.0f)),
	invBlock5(sf::Vector2f(2860.0f, 400.0f), sf::Vector2f(20.0f, 50.0f)),

	enemy1(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(1000.0f, 390.0f), 60.0f),
	enemy2(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(1000.0f, 230.0f), 30.0f),
	boss(sf::Vector2f(70.0f, 70.0f), sf::Vector2f(2500.0f, 465.0f), 50.0f)
{
	blocksTop = { floorBlock.getBoundings(), floorBlock2.getBoundings(), floorBlock3.getBoundings(), floorBlock4.getBoundings(), floorBlock5.getBoundings(),  platform1.getBoundings(), platform2.getBoundings(), platform3.getBoundings() };
	blocksFloor = { floorBlock.getBoundings(), floorBlock2.getBoundings(), floorBlock3.getBoundings(), floorBlock4.getBoundings(), floorBlock5.getBoundings() };
	blocksInvisible = { invBlock1.getBoundings(), invBlock2.getBoundings(), invBlock3.getBoundings(), invBlock4.getBoundings(), invBlock5.getBoundings() };
}

void Level::render(sf::RenderWindow& window)
{
	floorBlock.render(window);
	floorBlock2.render(window);
	floorBlock3.render(window);
	floorBlock4.render(window);
	floorBlock5.render(window);

	platform1.render(window);
	platform2.render(window);
	platform3.render(window);

	enemy1.render(window);
	enemy2.render(window);
	boss.render(window);
}

void Level::playerCollision(Player& player)
{
	player.collision(blocksTop, blocksFloor);
	enemy1.kill(player);
	enemy2.kill(player);
	boss.kill(player);
}

void Level::update(float dt, Player& player)
{
	enemy1.movement(blocksTop, blocksInvisible, dt);
	enemy2.movement(blocksTop, blocksInvisible, dt);
	boss.movement(blocksTop, blocksInvisible, dt);
	boss.update(dt, player.getPosition());
}
