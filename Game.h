#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Blocks.h"
#include "Level.h"

class Game
{
public:
	Game();

	void run();
	void render();
	void update();
	void handleEvents();

private:
	sf::RenderWindow window;

	sf::Clock clock;
	float dt;

	Player player;
	Level level;
};
