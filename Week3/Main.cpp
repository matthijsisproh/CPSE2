#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "action.hpp"
#include "circle.hpp"
#include "factory.hpp"
#include "rectangle.hpp"
#include "picture.hpp"
#include <array>
#include <string>
#include "error.hpp"

// Shift Operator
std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw end_of_file();
	}

	if (c != '(') {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw invalid_position(c);
	}

	if (!(input >> rhs.x)) {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw end_of_file();
	}

	if (!(input >> c)) {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw end_of_file();
	}

	if (!(input >> rhs.y)) {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw end_of_file();
	}

	if (!(input >> c)) {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw end_of_file();
	}

	if (c != ')') {
		std::cout << __FILE__ << ":" << __LINE__ << "\n" << std::flush;
		throw invalid_position(c);
	}

	return input;
}

std::ifstream & operator>>(std::ifstream & input, sf::Color & rhs) {
	std::string s;
	input >> s;

	const struct {
		const char * name; sf::Color color;
	}

	colors[]{
			{"red",    sf::Color::Red },
			{"white", sf::Color::White},
			{"green", sf::Color::Green},
			{"blue", sf::Color::Blue},
			{ "yellow", sf::Color::Yellow },
			{"magenta", sf::Color::Magenta},
			{"cyan", sf::Color::Cyan},
			{"Transparent", sf::Color::Transparent}
	};

	for (auto const & color : colors) {
		if (color.name == s) {
			rhs = color.color;
			std::cout << color.name;
			return input;
		}

	}
	if (s == "") {
		throw end_of_file();
	}
	throw unknown_color(s);
}

drawable * screen_object_read(std::ifstream & input) {
	sf::Vector2f position;
	sf::Vector2f position2;
	std::string filename;
	float size;
	sf::Color color;
	std::string name;
	input >> position >> name;


	if (name == "CIRCLE") {
		input >> color >> size;
		return new circle(position, size, color);
	}
	else if (name == "RECTANGLE") {
		input >> color >> position2;
		return new rectangle(position, position2, color);
	}
	else if (name == "PICTURE") {
		input >> filename;
		return new picture(position, filename);
	}
	else if (name == "") {
		throw end_of_file();
	}
	throw unknown_shape(name);
}


int main(int argc, char *argv[]) {
	//Open File
	std::ifstream input("config.txt");
	std::vector<drawable * > objects = {};
	
	try {
		for (;;) {
			objects.push_back(screen_object_read(input));
		}
	}
	catch (end_of_file) {
		//do nothing
	}

	catch (std::exception & problem) {
		std::cout << problem.what();
	}

	std::cout << "Factory\n";
	//Declarations
	sf::RenderWindow window{ sf::VideoMode{ 1080, 720 }, "SFML window" };

	while (window.isOpen()) {
		window.clear();
		sf::Texture texture;
		if (!texture.loadFromFile("download.png", sf::IntRect(10, 10, 32, 32)))
		{
			// error...
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);
		for (auto * object : objects) {
			object->draw(window);
		}
		window.display();

		sf::sleep(sf::milliseconds(2));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}