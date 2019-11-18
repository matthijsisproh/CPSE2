#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "block.hpp"

class wall : public drawable {
public:
	wall(sf::Vector2f position, sf::Vector2f size, sf::Vector3f color) :
		drawable(position, size, color)
	{}

	void draw(sf::RenderWindow & window) const override {
		block({ position }, { size }, color).draw(window);
	}

};

#endif //WALL_HPP