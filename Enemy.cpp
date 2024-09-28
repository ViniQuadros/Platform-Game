#include "Enemy.h"

Enemy::Enemy(sf::Vector2f size, sf::Vector2f position, float speed)
{
	if (!this->enemyTexture.loadFromFile("img/C_Enemy.png"))
	{
		std::cout << "Error loading enemy texture!" << std::endl;
	}
	enemy.setTexture(enemyTexture);
	enemy.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);

	this->enemy.setPosition(position);
	this->speed = speed;
	this->velocity.x = speed;
	this->scale = 1;
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
				this->enemy.setPosition(block.left - this->enemy.getGlobalBounds().getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = -speed;
				this->enemy.setScale(-scale, scale);
				break;
			}
			else if (this->enemy.getPosition().x < block.left + block.getSize().x + this->enemy.getGlobalBounds().getSize().x / 2)
			{
				this->enemy.setPosition(block.left + block.getSize().x + this->enemy.getGlobalBounds().getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = -speed;
				this->enemy.setScale(scale, scale);
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
				this->enemy.setPosition(invBlocks.left - this->enemy.getGlobalBounds().getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = -speed;
				this->enemy.setScale(-scale, scale);
				break;
			}
			else if (this->enemy.getPosition().x < invBlocks.left + invBlocks.getSize().x + this->enemy.getGlobalBounds().getSize().x / 2)
			{
				this->enemy.setPosition(invBlocks.left + invBlocks.getSize().x + this->enemy.getGlobalBounds().getSize().x / 2, this->enemy.getPosition().y);
				this->velocity.x = speed;
				this->enemy.setScale(scale, scale);
				break;
			}
		}
	}

	this->enemy.move(velocity * dt);
}
