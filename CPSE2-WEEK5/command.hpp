#pragma once

class Command {
public:
	Command(char type):
		player_type(type)
	{}
	virtual void execute(std::vector<char>& board) = 0;
protected:
	const char player_type;
};

class MoveCommand_TOPLEFT : public Command{
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[0] = player_type; 
	}
};

class MoveCommand_TOPCENTER : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[1] = player_type;
	}
};

class MoveCommand_TOPRIGHT: public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[2] = player_type;
	}
};

class MoveCommand_CENTERLEFT : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[3] = player_type;
	}
};

class MoveCommand_CENTERCENTER : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[4] = player_type;
	}
};

class MoveCommand_CENTERRIGHT : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[5] = player_type;
	}
};

class MoveCommand_BOTTOMLEFT : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[6] = player_type;
	}
};

class MoveCommand_BOTTOMCENTER : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[7] = player_type;
	}
};

class MoveCommand_BOTTOMRIGHT : public Command {
public:
	using Command::Command;
	void execute(std::vector<char>& board)override {
		board[8] = player_type;
	}
};