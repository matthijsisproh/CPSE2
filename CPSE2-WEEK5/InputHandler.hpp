#pragma once
#include "command.hpp"
#include "GameActor.hpp"
#define NULL 0

class InputHandler {
public:
	InputHandler() {}

	Command* handleInput(char player_type, int & position) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) { position = 0; return new MoveCommand_TOPLEFT(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) { position = 1; return new MoveCommand_TOPCENTER(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) { position = 2; return new MoveCommand_TOPRIGHT(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) { position = 3; return new MoveCommand_CENTERLEFT(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) { position = 4; return new MoveCommand_CENTERCENTER(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) { position = 5; return new MoveCommand_CENTERRIGHT(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) { position = 6; return new MoveCommand_BOTTOMLEFT(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) { position = 7; return new MoveCommand_BOTTOMCENTER(player_type); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) { position = 8; return new MoveCommand_BOTTOMRIGHT(player_type); }
		return NULL;
	}

	bool CTRLZ_pressed() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	Command* UNDO;
};
