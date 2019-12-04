#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "rectangle.hpp"

class picture : public drawable{
public:
	picture(sf::Vector2f position, std::string filename) :
		drawable(position, size, color), filename(filename)
	{}

	void draw(sf::RenderWindow & window) const override {
		
	}

private:
	std::string filename;
	float size = 0.0;
	sf::Color color = sf::Color::White;
};

#endif //PICTURE_HPP