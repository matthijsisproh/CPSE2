#include <SFML/Graphics.hpp>
#include "ball.hpp"

Ball::Ball(sf::Vector2f position, float size) :
	Drawable(position, size)
{}

void Ball::draw(sf::RenderWindow& window)override{
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}

void Ball::move(sf::Vector2f delta) {
	position += delta;
}

void Ball::jump(sf::Vector2f target) {
	position = target;
}

void Ball::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	));
}