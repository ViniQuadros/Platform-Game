#include "Enemy.h"

Enemy::Enemy(sf::Vector2f size, sf::Vector2f position, float speed)
{
	this->enemy.setPosition(position);
	this->enemy.setSize(size);
	this->speed = speed;
	this->velocity.x = speed;
	this->enemy.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	this->enemy.setFillColor(sf::Color::Red);
}

void Enemy::render(sf::RenderWindow& window)
{
	window.draw(this->enemy);
}

void Enemy::kill(Player& player)
{
	if (this->enemy.getGlobalBounds().intersects(player.playerBounds()))
	{
		player.restart();
	}
}

void Enemy::movement(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& invisibleBlocks, float dt)
{
	for (const auto& block : blocks)
	{
		if (this->enemy.getGlobalBounds().intersects(block))
		{
			if (this->enemy.getPosition().x < block.left)
			{
				this->enemy.setPosition(block.left - enemy.getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = -speed;
				break;
			}
			else if (this->enemy.getPosition().x < block.left + block.getSize().x + enemy.getSize().x / 2)
			{
				this->enemy.setPosition(block.left + block.getSize().x + enemy.getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = -speed;
				break;
			}
		}
	}

	for (const auto& invBlocks : invisibleBlocks)
	{
		if (this->enemy.getGlobalBounds().intersects(invBlocks))
		{
			if (this->enemy.getPosition().x < invBlocks.left)
			{
				this->enemy.setPosition(invBlocks.left - this->enemy.getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = -speed;
				break;
			}
			else if (this->enemy.getPosition().x < invBlocks.left + invBlocks.getSize().x + enemy.getSize().x / 2)
			{
				this->enemy.setPosition(invBlocks.left + invBlocks.getSize().x + this->enemy.getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = speed;
				break;
			}
		}
	}

	enemy.move(velocity * dt);
}
