#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

class Drawable {
protected:
	sf::Vector2f position;
	sf::Color color;
	float size;

public:
	Drawable(sf::Vector2f position, sf::Color color, float size) :
		position(position), size(size), color(color)
	{}

	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void update(sf::Vector2f new_position) = 0;

	virtual bool inHitbox(sf::Vector2f mouse_pos) = 0;
	
	virtual void write_object_to_file(std::ofstream& output) = 0;

};


#endif