#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "drawable.hpp"

class Rectangle : public Drawable {
private:
	sf::Vector2f size;
	
public:
	Rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
		Drawable(position, color, size.x), size(size)
	{}

	void draw(sf::RenderWindow& window)override {
		sf::RectangleShape rectangle({ 30, 40 });
		rectangle.setPosition(position);
		rectangle.setFillColor(color);
		window.draw(rectangle);
	}

	void update(sf::Vector2f new_position)override {
		position = { new_position.x - 10, new_position.y - 10 };
	}

	bool inHitbox(sf::Vector2f mouse_pos)override {
		if (mouse_pos.x >= position.x && mouse_pos.x <= position.x + int(size.x) && mouse_pos.y >= position.y && mouse_pos.y <= position.y + int(size.x)) {
			return true;
		}
		else {
			return false;
		}
	}

	void write_object_to_file(std::ofstream& output)override {
		output << "(" << position.x << ", " << position.y << ") " << "RECTANGLE red " << "(" << size.x << ", " << size.y << ")\n";
	}
};


#endif //RECTANGLE_HPP