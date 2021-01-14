#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

class Drawable {
private:
	sf::Vector2f position;
	float size;

public:
	Drawable(sf::Vector2f position, float size) :
		position(position), size(size)
	{}

	virtual void draw(sf::RenderWindow& window){}








};


#endif