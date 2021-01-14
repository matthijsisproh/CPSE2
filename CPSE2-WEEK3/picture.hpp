#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"

class Picture : public Drawable {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string FileName;
	sf::Color color = sf::Color::White;
	float size = 30.0;


public:
	Picture(sf::Vector2f position, std::string FileName) :
		Drawable(position, color, 0), FileName(FileName)
	{
		if (!texture.loadFromFile(FileName))
		{
			std::cout << "ERROR OCCURRED!";
		}
		sprite.scale(sf::Vector2f(0.5, 0.5));
		sprite.setPosition(position);
		sprite.setTexture(texture);
	}

	void draw(sf::RenderWindow& window)override {
		sprite.setPosition(position);
		window.draw(sprite);
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

	void write_object_to_file(std::ofstream& output)override {
		output << "(" << position.x << ", " << position.y << ") " << "PICTURE " << FileName << "\n";
	}



};

#endif //PICTURE_HPP