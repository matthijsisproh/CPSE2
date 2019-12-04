#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class rectangle : public drawable {
public:
	rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
		drawable{ position, size.x, color }, size(size)
	{}

	void draw(sf::RenderWindow & window) const override {
		sf::RectangleShape Rectangle;
		Rectangle.setPosition(position);
		Rectangle.setSize(size);
		Rectangle.setFillColor(color);
		window.draw(Rectangle);
	}
private:
	sf::Vector2f size;

};

#endif //RECTANGLE_HPP