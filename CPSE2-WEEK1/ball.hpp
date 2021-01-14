#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class Ball : public Drawable {
public:
	Ball(sf::Vector2f position, float size = 30.0);

	void draw(sf::RenderWindow& window)override {
	}

	void move(sf::Vector2f delta);

	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);

private:
	sf::Vector2f position;
	float size;
};

#endif