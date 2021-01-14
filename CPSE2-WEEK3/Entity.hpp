#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using vec2 = sf::Vector2f;

class Entity
{
public:
	Entity(vec2 pos, vec2 size, const std::string& file);

	void render(sf::RenderWindow& window);

	const std::string& getTextureName();

private:
	vec2 p_size;
	vec2 p_pos;

	sf::Texture p_texture;

	std::string p_textureName;
};