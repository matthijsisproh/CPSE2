#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class block : public drawable {
public:
	block(sf::Vector2f position, sf::Vector2f size, sf::Vector3f color) :
		drawable{ position, size, color}
	{}

	void draw(sf::RenderWindow & window) const override{
		sf::RectangleShape Rectangle;
		Rectangle.setPosition(position);
		Rectangle.setSize(size);
		Rectangle.setFillColor(sf::Color(sf::Uint8(color.x), sf::Uint8(color.y), sf::Uint8(color.z)));
		window.draw(Rectangle);
	}

};

#endif //BLOCK_HPP
