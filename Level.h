#pragma once

#include "Blocks.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

class Level
{
public:
	Level();

	void render(sf::RenderWindow& window);
	void playerCollision(Player& player);
	void update(float dt, Player& player);

private:
	Blocks floorBlock;
	Blocks floorBlock2;
	Blocks floorBlock3;
	Blocks floorBlock4;
	Blocks floorBlock5;

	Blocks platform1;
	Blocks platform2;

	Blocks invBlock1;
	Blocks invBlock2;
	Blocks invBlock3;
	Blocks invBlock4;
	Blocks invBlock5;

	Enemy enemy1;
	Enemy enemy2;
	Boss boss;

	std::vector<sf::FloatRect> blocksTop;
	std::vector<sf::FloatRect> blocksFloor;
	std::vector<sf::FloatRect> blocksInvisible;
};