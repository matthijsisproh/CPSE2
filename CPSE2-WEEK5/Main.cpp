#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "game.hpp"
#include "command.hpp"
#include "GameActor.hpp"
#include "InputHandler.hpp"
#include "GUI.hpp"
#include "Picture.hpp"

//TODO
// STL CONTAINER MET VERLOOP VAN HET SPEL // game_state
// UNDO feature hiermee verwijder je het laatste zet van het spel
// Een Interface versie maken
// Text only applicatie

int main() {
	bool InterfaceON = true;
	Game game;
	if (InterfaceON) {
		GUI interface;
		game.start(interface);
		
	
	}
	else {
		game.start();
		//game.execute();
	}

}
