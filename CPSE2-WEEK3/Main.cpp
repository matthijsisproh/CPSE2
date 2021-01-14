#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "rectangle.hpp"
#include "drawable.hpp"
#include "picture.hpp"
#include <fstream>
#include <vector>
#include "exceptions.hpp"
#include "factory.hpp"
#include "action.hpp"

//Main
int main(int argc, char* argv[]) {
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	std::vector<Drawable*> objects = {};
	std::ifstream input("objects.txt");
	try {
		for (;;) {
			objects.push_back(screen_object_read(input));
		}
	}
	catch (end_of_file) {
		// do nothing
	}
	catch (std::exception & problem) {
		std::cout << problem.what();
	}
	
	while(window.isOpen()){
		window.clear();
		for (auto& p : objects) {
			static sf::Vector2i oldMousePos;
			auto mousePos = sf::Mouse::getPosition(window);
			if (p->inHitbox(sf::Vector2f(mousePos)))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					p->update(sf::Vector2f(mousePos));
				
				}
			}
			p->draw(window);
		}

		window.display();
			
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::ofstream output;
	output.open("objects.txt", std::ofstream::out);
	output << "";
	output.close();
	output.open("objects.txt", std::ofstream::app | std::ofstream::out);
	for (auto& object : objects) {
		object->write_object_to_file(output);
	}
	output.close();

	std::cout << "Terminating application\n";
	return 0;
}