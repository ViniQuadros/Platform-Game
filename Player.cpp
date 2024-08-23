#include "Player.h"

Player::Player(sf::Vector2f size, float speed)
{
	this->player.setSize(size);
	this->speed = speed;
	this->size = size;
	this->player.setPosition(sf::Vector2f(300, 100));
	this->player.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	this->player.setFillColor(sf::Color::Red);
	this->velocity.x = 0.0f;
	this->velocity.y = 0.0f;
	this->onAir = true;
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(this->player);
}

void Player::update(float dt)
{
	if (velocity.y <= maxY)
		velocity += gravity * dt;

	this->inputHandle(dt);
	//std::cout << velocity.y << std::endl;
	std::cout << onAir << std::endl;
}

void Player::inputHandle(float dt)
{
	this->velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->velocity.x += -speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->velocity.x += speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !onAir)
	{
		this->velocity.y += -maxY * dt;
	}

	this->player.move(this->velocity);
}

void Player::collision(sf::FloatRect block)
{
	if (this->player.getGlobalBounds().intersects(block))
	{
		this->onAir = false;
		this->player.setPosition(player.getPosition().x, block.top - size.y / 2);
	}
	else {
		this->onAir = true;
	}
}
