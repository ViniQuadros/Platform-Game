#pragma once

#include "Blocks.h"
#include "Player.h"
#include "Enemy.h"

class Level
{
public:
	Level();

	void render(sf::RenderWindow& window);
	void playerCollision(Player& player);
	void update(float dt);

private:
	Blocks floorBlock;
	Blocks floorBlock2;
	Blocks floorBlock3;

	Blocks platform1;
	Blocks platform2;

	Enemy enemy1;

	std::vector<sf::FloatRect> blocksTop;
	std::vector<sf::FloatRect> blocksFloor;
};