#include "Blocks.h"

Blocks::Blocks(sf::Vector2f position, sf::Vector2f size)
{
	this->block.setPosition(position);
	this->block.setSize(size);
	this->block.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	this->blockBoundings = this->block.getGlobalBounds();
}

void Blocks::render(sf::RenderWindow& window)
{
	window.draw(this->block);
}

sf::FloatRect Blocks::getBoundings()
{
	return this->blockBoundings;
}
