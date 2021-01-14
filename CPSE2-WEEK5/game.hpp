#pragma once
#include "GameActor.hpp"
#include "InputHandler.hpp"
#include "GUI.hpp"

class Game {
private:
	std::vector<Command*> p_commands;
	InputHandler inputHandler;
	int newCommandPos = 0;

public:
	Game() {}

	//GUI GAME
	void start(GUI & interface) {
		char player_type = 'X';
		//Start GUI interface or text-only interface
		//Ask input
		while (interface.updateWindow()) {
			if (addCommand(player_type)) {
				interface.addObject(player_type, newCommandPos);
				player_type = switchTurn(player_type);
			}

			if (inputHandler.CTRLZ_pressed()) {
				undo();
				interface.undo();
				sf::sleep(sf::milliseconds(200));
			}

			if (checkWinner() != 'E' | p_commands.size() == 9) {
				interface.empty();
				break;
				
			}
			interface.drawObjects();
			
		}
	}


	void start() {
		auto board = getCurrentBoardState();
		char player_type = 'X';
		printBoard();
		for (;;) {
			if (addCommand(player_type)) {
				player_type = switchTurn(player_type);
				printBoard();
			}

			if (inputHandler.CTRLZ_pressed()) {
				undo();
				printBoard();
				sf::sleep(sf::milliseconds(200));
			}

			if (checkWinner() != 'E' or p_commands.size() == 9) {
				emptyBoard();
				sf::sleep(sf::milliseconds(200));
				printBoard();
			}
			
		}
		
	}

	bool addCommand(char player_type) {
		auto board = getCurrentBoardState();
		Command* newCommand = nullptr;
		newCommand = inputHandler.handleInput(player_type, newCommandPos);
		if (board[newCommandPos] != 'E') {
			return false;
		}

		if (newCommand)
		{
			p_commands.push_back(newCommand);
			return true;
		}
		else {
			return false;

		}
		
		
	}

	char switchTurn(char & player_type) {
		if (player_type == 'X') {
			return player_type = 'O';
		}
		if (player_type == 'O') {
			return player_type = 'X';
		}
	}


	char checkWinner(){
		// Loop through commands
		auto board = getCurrentBoardState();

		// Return the possible winner
		char players[2] = { 'X', 'O' };
		for (auto& player : players)
		{
			if
				(
					board[0] == player && board[1] == player && board[2] == player ||
					board[3] == player && board[4] == player && board[5] == player ||
					board[6] == player && board[7] == player && board[8] == player ||
					board[0] == player && board[3] == player && board[6] == player ||
					board[1] == player && board[4] == player && board[7] == player ||
					board[2] == player && board[5] == player && board[8] == player ||
					board[0] == player && board[4] == player && board[8] == player ||
					board[2] == player && board[4] == player && board[6] == player
					)
			{
				std::cout << "Player " << player << " Has won!";
				return player;
			}
		}

		// No winner cuz game ended
		if (p_commands.size() == 9)
		{
			return 'F';
		}

		// No winner yet
		return 'E';
	}

	std::vector<char> getCurrentBoardState(){
		// Loop through the moves
		std::vector<char> board = { 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E' };

		for (auto& command : p_commands)
		{
			command->execute(board);
		}

		return board;
	}

	void emptyBoard() {
		for (auto& command : p_commands) {
			p_commands.pop_back();
		}
	}


	void printBoard() {
		system("CLS");
		auto board = getCurrentBoardState();
		std::cout << "|";
		for (unsigned int i = 1; i <= 9; i++) {
			std::cout << board[i-1] << " | ";
			if (i % 3 == 0) {
				std::cout << "\n|";
			}

		}
		std::cout << "\n";

	}

	void undo() {
		if (!p_commands.empty()) {
			p_commands.pop_back();
		}
	}
	
};
