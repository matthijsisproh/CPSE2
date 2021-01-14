#include <iostream>

#include "Entity.hpp"

Entity::Entity(vec2 pos, vec2 size, const std::string& file) :
	p_pos(pos), p_size(size), p_textureName(file)
{
	p_texture.loadFromFile(file);
}

void Entity::render(sf::RenderWindow& window)
{
	sf::RectangleShape rect;

	rect.setPosition(p_pos);
	rect.setSize(p_size);
	rect.setTexture(&p_texture);

	window.draw(rect);
}

const std::string& Entity::getTextureName()
{
	return p_textureName;
}