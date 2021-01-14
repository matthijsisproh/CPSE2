#pragma once
#include <string>
#include <iostream>

class Picture {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string FileName;
	sf::Vector2f m_pos;


public:
	Picture(sf::Vector2f position, std::string FileName) :
		m_pos(position), FileName(FileName)
	{}

	void init() {
		if (!texture.loadFromFile(FileName))
		{
			std::cout << "ERROR OCCURRED!";
		}
		sprite.scale(sf::Vector2f(3, 3));
		sprite.setPosition(m_pos);
		sprite.setTexture(texture);
	}

	void draw(sf::RenderWindow& window) {
		sprite.setPosition(m_pos);
		window.draw(sprite);
	}

};