#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>

//Errors
class end_of_file : public std::exception {
public:
	end_of_file() :
		s{ std::string{ "end_of_file" } }
	{}
	const char * what() const noexcept override {
		return s.c_str(); // return pointer to null-terminated immutable array
	}
private:
	std::string s;
};

class invalid_position : public std::exception {
public:
	invalid_position(const char & name) :
		s{ std::string{ "invalid_position [" } +name + "]" }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_color : public std::exception {
public:
	unknown_color(const std::string & name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_shape : public std::exception {
public:
	unknown_shape(const std::string & name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};


#endif ERROR_HPP