#include "Player.h"

Player::Player(sf::Vector2f size, float speed)
{
	this->player.setSize(size);
	this->speed = speed;
	this->size = size;
	this->initialPosition = sf::Vector2f(800, 200);
	this->player.setPosition(initialPosition);
	this->player.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	this->player.setFillColor(sf::Color::Blue);
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
	//std::cout << player.getPosition().y << std::endl;
}

void Player::update(float dt)
{
	this->viewport.setCenter(player.getPosition() - sf::Vector2f(0, 25));

	if (this->velocity.y <= this->maxY)
		this->velocity += this->gravity * dt;

	this->inputHandle(dt);
	this->killHeight();
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

void Player::collision(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& blocksFloor)
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
	for (const auto& block : blocksFloor)
	{
		if (this->player.getGlobalBounds().intersects(block))
		{
			if (this->player.getPosition().x < block.left)
			{
				this->player.setPosition(block.left - size.x / 2, this->player.getPosition().y);
				this->velocity.x = 0.0f;
				break;
			}
			else if (this->player.getPosition().x < block.left + block.getSize().x + size.x / 2)
			{
				this->player.setPosition(block.left + block.getSize().x + size.x / 2, this->player.getPosition().y);
				this->velocity.x = 0.0f;
				break;
			}
		}
	}

	this->isOnAir = !isOnAnyBlock;
}

sf::FloatRect Player::playerBounds()
{
	return player.getGlobalBounds();
}

void Player::killHeight()
{
	if (player.getPosition().y >= 800.0f)
	{
		restart();
	}
}

void Player::restart()
{
	this->player.setPosition(initialPosition);
	this->velocity.x = 0.0f;
	this->velocity.y = 0.0f;
}
