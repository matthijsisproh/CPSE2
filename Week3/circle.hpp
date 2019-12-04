#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle : public drawable {
public:
	circle(sf::Vector2f position, float size, sf::Color color):
		drawable{ position, size, color }
	{}

	void draw(sf::RenderWindow & window) const {
		sf::CircleShape circle;
		circle.setRadius(size);
		circle.setPosition(position);
		circle.setFillColor(color);
		window.draw(circle);
	}
};

#endif //CIRCLE_HPP