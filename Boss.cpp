#include "Boss.h"
#include <cmath>

Boss::Boss(sf::Vector2f size, sf::Vector2f position, float speed) :
    Enemy(size, position, speed)
{
    if (!this->enemyTexture.loadFromFile("img/B_Enemy.png"))
    {
        std::cout << "Error loading boss texture!" << std::endl;
    }
    this->enemy.setTexture(this->enemyTexture);
    this->enemy.setOrigin(this->enemyTexture.getSize().x / 2, this->enemyTexture.getSize().y / 2);
    this->enemy.setScale(2, 2);

    this->enemy.setPosition(position);
    this->speed = speed;
    this->velocity.x = speed;
    
    this->canAttack = false;
    this->isOnAnyBlock = false;
    this->delay = rand() % 6;
    this->scale = 2;
}

void Boss::update(float dt)
{
    //std::cout << "X: " << this->enemy.getPosition().x << "Y: " << this->enemy.getPosition().y << std::endl;

    if (this->velocity.y <= this->maxY)
        this->velocity += this->gravity * dt;

    if (clock.getElapsedTime().asSeconds() > delay)
    {
        canAttack = true;
        this->delay = rand() % 10;
        clock.restart();
    }

    if (canAttack)
    {
        jumpAttack(dt);
    }
}

void Boss::render(sf::RenderWindow& window)
{
    window.draw(this->enemy);
}

void Boss::movement(const std::vector<sf::FloatRect>& blocks, const std::vector<sf::FloatRect>& invisibleBlocks, float dt)
{
    Enemy::movement(blocks, invisibleBlocks, dt);

    isOnAnyBlock = false;

    for (const auto& block : blocks)
    {
        if (this->enemy.getGlobalBounds().intersects(block))
        {
            if (this->velocity.y > 0 && this->enemy.getPosition().y < block.top)
            {
                this->enemy.setPosition(this->enemy.getPosition().x, block.top - this->enemy.getGlobalBounds().getSize().y / 2);
                this->velocity.y = 0.0f;
                this->isOnAnyBlock = true;
                break;
            }
        }
    }
}

void Boss::jumpAttack(float dt)
{
    this->velocity.y += -maxY * dt;
    canAttack = false;
}






