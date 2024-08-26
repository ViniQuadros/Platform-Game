#include "Player.h"

Player::Player(sf::Vector2f size, float speed)
{
	this->player.setSize(size);
	this->speed = speed;
	this->size = size;
	this->initialPosition = sf::Vector2f(300, 200);
	this->player.setPosition(initialPosition);
	this->player.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	this->player.setFillColor(sf::Color::Red);
	this->isOnAir = true;
	this->isOnAnyBlock = false;

	this->viewport.reset(sf::FloatRect(0, 0, 800.f, 600.f));
	this->viewport.setSize(sf::Vector2f(600, 400));
	this->viewport.setViewport(sf::FloatRect(0, 0, 1, 1));
}

void Player::render(sf::RenderWindow& window)
{
	window.setView(this->viewport);
	window.draw(this->player);
}

void Player::update(float dt)
{
	this->viewport.setCenter(player.getPosition() - sf::Vector2f(0, 25));

	std::cout << player.getPosition().y << std::endl;
	if (this->velocity.y <= this->maxY)
		this->velocity += this->gravity * dt;

	this->inputHandle(dt);
	this->die();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isOnAir)
	{
		this->velocity.y += -maxY * dt;
	}

	this->player.move(this->velocity);
}

void Player::collision(const std::vector<sf::FloatRect>& blocks)
{
	isOnAnyBlock = false;
	for (const auto& block : blocks)
	{
		if (this->player.getGlobalBounds().intersects(block))
		{
			if (this->velocity.y > 0 && this->player.getPosition().y < block.top)
			{
				this->player.setPosition(this->player.getPosition().x, block.top - size.y / 2);
				this->velocity.y = 0.0f;
				this->isOnAnyBlock = true;
				break;
			}
		}
	}
	this->isOnAir = !isOnAnyBlock;
}

void Player::die()
{
	if (player.getPosition().y >= 800.0f)
	{
		player.setPosition(initialPosition);
	}
}
