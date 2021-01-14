#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Picture.hpp"
#include <iostream>

#define WINDOW_SIZE 900


class ScreenObject
{
public:
	ScreenObject(sf::Vector2f pos, sf::Vector2f size, const std::string& file) :
		p_pos(pos), p_size(size), p_textureName(file)
	{
		p_texture.loadFromFile(file);
	}


	void render(sf::RenderWindow& window)
	{
		sf::RectangleShape rect;

		rect.setPosition(p_pos);
		rect.setSize(p_size);
		rect.setTexture(&p_texture);

		window.draw(rect);
	}

	const std::string& getTextureName()
	{
		return p_textureName;
	}

private:
	sf::Vector2f p_size;
	sf::Vector2f p_pos;

	sf::Texture p_texture;

	std::string p_textureName;
};


class GUI{
private:
	sf::RenderWindow p_window;
	char current_player = 'X';
	std::vector<ScreenObject> p_objects;

public:
	GUI() :
		p_window{ sf::VideoMode{ WINDOW_SIZE, WINDOW_SIZE }, "Tic Tac Toe" }
	{
		p_objects.push_back(ScreenObject({ 0, 0 }, { WINDOW_SIZE, WINDOW_SIZE }, "tictactoegrid.png"));
	}

	bool updateWindow() {
		//p_undoKeyPressed = false;
		p_window.display();
		sf::Event event;
		while (p_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				p_window.close();
			}
		}

		return p_window.isOpen();
	}

	void addObject(char player_type, int position) {
		std::string filename; 
		sf::Vector2f pos; 
		if (player_type == 'X') {
			filename = "cross.png";
		}
		if (player_type == 'O') {
			filename = "nought.png";
		}

		if (position == 0) { pos = { 25, 25 }; }
		if (position == 1) { pos = { 325, 25 }; }
		if (position == 2) { pos = { 625, 25 }; }
		if (position == 3) { pos = { 25, 325 }; }
		if (position == 4) { pos = { 325, 325 }; }
		if (position == 5) { pos = { 625, 325 }; }
		if (position == 6) { pos = { 25, 625 }; }
		if (position == 7) { pos = { 325, 625 }; }
		if (position == 8) { pos = { 625, 625 }; }
		p_objects.push_back(ScreenObject(pos, { 250, 250 }, filename));
		
	}

	void undo() {
		p_objects.pop_back();
	}

	void empty() {
		for (auto& object : p_objects) {
			p_objects.pop_back();
		}
	}

	void drawObjects() {
		for (auto& object : p_objects) {
			object.render(p_window);
		}
	}

	void updateMouse(char& player, sf::Vector2i& pos)
	{
		auto mousePos = sf::Mouse::getPosition(p_window);
	}



};