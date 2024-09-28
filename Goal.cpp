#include "Goal.h"

Goal::Goal()
{
	if (!this->texture.loadFromFile("img/Goal.png"))
	{
		std::cout << "Error on loading texture." << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);

	this->speed = 20.0f;
	this->end = false;

	this->sprite.setPosition(sf::Vector2f(3000, 325));
}

void Goal::render(sf::RenderWindow& window)
{
	window.draw(this->sprite);
	window.draw(this->sprite);
}

void Goal::update(float dt)
{
	this->velocity.y = this->speed;
	this->sprite.move(this->velocity * dt);

	if (this->sprite.getPosition().y < 300 || this->sprite.getPosition().y > 350)
	{
		this->speed *= -1;
	}
}

void Goal::win(Player& player)
{
	if (this->sprite.getGlobalBounds().intersects(player.playerBounds()))
	{
		this->end = true;
	}
}

bool Goal::hasEnded()
{
	return this->end;
}
