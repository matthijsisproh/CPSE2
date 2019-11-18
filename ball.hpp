#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable{
public:
	ball(sf::Vector2f position, sf::Vector2f size, sf::Vector3f color) :
		drawable{ position, size, color}
	{}

	void draw(sf::RenderWindow & window) const {
		sf::CircleShape circle;
		circle.setRadius(size.x);
		circle.setPosition(position);
		circle.setFillColor(sf::Color(sf::Uint8(color.x), sf::Uint8(color.y), sf::Uint8(color.z)));
		window.draw(circle);
	}
	
	void update() override {
		if (bounced == 0) {
			position.x += 1;
			position.y += 1;
		}

		else if (bounced == 1) {
			position.x += 1;
			position.y -= 1;
		}

		else if (bounced == 2) {
			position.x -= 1;
			position.y -= 1;
		}

		else if (bounced == 4) {
			position.x -= 1;
			position.y += 1;
		}
	}

	bool getInteract(sf::CircleShape circle) {
		return circle.getGlobalBounds().intersects(circle.getGlobalBounds());
	}

	void interact(drawable & other) override {
		if (this != &other) {
			if (overlaps(other)) {
				if (overlaps(other)) {
					sf::sleep(sf::milliseconds(1));
					std::cout << "OVERLAPSED";
					bounced++;

					if (bounced > 4) {
						bounced = 0;
					}
				}

			}
		}
	}

private:
	int bounced = 0;
};

#endif