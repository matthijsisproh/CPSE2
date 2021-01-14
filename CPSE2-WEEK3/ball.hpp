#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <fstream>

class Ball : public Drawable {
public:
	Ball(sf::Vector2f position, sf::Color color, float size = 30.0) :
		Drawable(position, color, size)
	{}

	void draw(sf::RenderWindow& window)override {
		sf::CircleShape circle;
		circle.setRadius(size);
		circle.setPosition(position);
		circle.setFillColor(color);
		window.draw(circle);
	}

	void update(sf::Vector2f new_position)override {
		position = { new_position.x - 10, new_position.y - 10 };
	}

	bool inHitbox(sf::Vector2f mouse_pos)override {
		if (mouse_pos.x >= position.x && mouse_pos.x <= position.x + int(size) && mouse_pos.y >= position.y && mouse_pos.y <= position.y + int(size)) {
			return true;
		}
		else {
			return false;
		}
	}

	void move(sf::Vector2f delta) {
		position += delta;
	}

	void jump(sf::Vector2f target) {
		position = target;
	}
	void jump(sf::Vector2i target) {
		jump(sf::Vector2f(
			static_cast<float>(target.x),
			static_cast<float>(target.y)
		));
	}

	void write_object_to_file(std::ofstream& output)override {
		output << "(" << position.x << ", " << position.y << ") " << "CIRCLE blue " << size << "\n";

	}

};



#endif