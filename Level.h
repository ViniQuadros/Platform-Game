#pragma once

#include "Blocks.h"
#include "Player.h"

class Level
{
public:
	Level();

	void render(sf::RenderWindow& window);
	void update(Player& player);

private:
	Blocks floorBlock;
	Blocks platform1;
};