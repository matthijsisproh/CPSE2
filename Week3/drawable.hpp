#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
public:
	drawable(sf::Vector2f position, float size, sf::Color color):
		position{ position }, size{ size }, color{color}
	{}

	virtual void draw(sf::RenderWindow & window) const {}

	virtual void move(sf::Vector2f delta) {
		position += delta;
	}

	virtual void jump(sf::Vector2f target) {
		position = target;
	}

	virtual void jump(sf::Vector2i target) {
		jump(sf::Vector2f(
			static_cast<float>(target.x),
			static_cast<float>(target.y)
		));
	}

	virtual void add(drawable & other) {}


	virtual void update() {}

	virtual void interact(drawable & other) {}

	bool within(int x, int a, int b) {
		return (x >= a) && (x <= b);
	}

	bool overlaps(const drawable & other) {

		bool x_overlap = within(
			position.x,
			other.position.x, 
			other.position.x + other.size
		) || within(
			other.position.x,
			position.x,
			position.x + size
		);

		bool y_overlap = within(
			position.y,
			other.position.y,
			other.position.y + other.size
		) || within(
			other.position.y,
			position.y,
			position.y + size
		);

		return x_overlap && y_overlap;
	}

protected:
	sf::Vector2f position;
	float size;
	sf::Color color;

};


#endif //DRAWABLE_HPP
