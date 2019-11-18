#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "block.hpp"
#include "wall.hpp"
#include "action.hpp"
#include <array>

int main(int argc, char *argv[]) {
	std::cout << "Bouncing Ball, interactive block\n";
	sf::RenderWindow window{ sf::VideoMode{ 1080, 720 }, "SFML window" };
	//ball my_block({ 320.0, 300.0 }, 5.0);
	block my_block({ 50.0, 100.0 }, { 100.0, 30.0 }, { 255, 0, 0 });
	ball my_ball({ 320.0, 300.0 }, { 30.0, 30.0 }, { 0, 255, 0 });
	wall my_wall0({ 0.0, 0.0 }, { 30.0, 720.0 }, { 0, 255, 255 });
	wall my_wall1({ 1050.0, 0.0 }, { 30.0, 720.0 }, { 0, 255, 255 });
	wall my_wall2({ 30.0, 0.0 }, { 1020.0, 30.0 }, { 0, 255, 255 });
	wall my_wall3({ 30.0, 690.0 }, { 1020.0, 30.0 }, { 0, 255, 255 });
	std::array< drawable *, 6> objects = { &my_block, &my_ball, &my_wall0, &my_wall1, &my_wall2, &my_wall3};

	action actions[] = {
		action(sf::Keyboard::Left,  [&]() { my_block.move(sf::Vector2f(-1.0,  0.0)); }),
		action(sf::Keyboard::Right, [&]() { my_block.move(sf::Vector2f(+1.0,  0.0)); }),
		action(sf::Keyboard::Up,    [&]() { my_block.move(sf::Vector2f(0.0, -1.0)); }),
		action(sf::Keyboard::Down,  [&]() { my_block.move(sf::Vector2f(0.0, +1.0)); }),
		action(sf::Mouse::Left,     [&]() { my_block.jump(sf::Mouse::getPosition(window)); })
	};

	while (window.isOpen()) {
		window.clear();
		for (auto & p : objects) {
			p->draw(window);
			p->update();
		
		}

		for (auto & action : actions) {
			action();
		}
		window.display();
		sf::sleep(sf::milliseconds(2));

		for (auto & p : objects) {
			for (auto & other : objects) {
				p->interact(*other);
			}
		}

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