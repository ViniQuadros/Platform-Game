#include "Game.h"

Game::Game() :
	player(sf::Vector2f(20.0f, 20.0f), 150.0f)
{
	window.create(sf::VideoMode(800, 600), "Platformer");
	window.setFramerateLimit(60);

	dt = clock.restart().asSeconds();
}

void Game::run()
{
	while (window.isOpen())
	{
		render();
		update();
		handleEvents();
	}
}

void Game::render()
{
	window.clear();

	level.render(window);
	player.render(window);

	window.display();
}

void Game::update()
{
	player.update(dt);
	level.playerCollision(player);
	level.update(dt);
}

void Game::handleEvents()
{
	dt = clock.restart().asSeconds();

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window.close();
	}
}
