#ifndef CPP06_CONVERTOR_HPP
#define CPP06_CONVERTOR_HPP

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <limits>
#include <cmath>

#define DEBUG "\033[1;36m"
#define ERROR "\033[1;31m"
#define RESET "\033[0;0m"

void eprintln(std::string str);
void dprintln(std::string str);

class Convertor {
public:
	Convertor(std::string input);
	Convertor(const Convertor &src);
	Convertor &operator=(const Convertor &rhs);
	virtual ~Convertor();

	class InvalidInputException: public std::exception {
		virtual const char* what() const throw()
		{
			return "Input is invalid, please double check :/";
		}
	};

	void printTypes();

private:
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	bool parseInput();
	bool parseWeirdInput();

	const std::string input;
	std::string type;

	int iValue;
	char cValue;
	float fValue;
	double dValue;
};

#endif
