#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int choice = (std::rand()) % 3;

	if (choice == 0)
		return new A;
	if (choice == 1)
		return new B;
	return new C;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "Identified class A!" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identified class B!" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identified class C!" << std::endl;
	else
		std::cout << "What the heck?" << std::endl;
}

void identify(Base &p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Identified class A!" << std::endl;
	} catch (std::exception &e) {
		(void) e;
		try {
			(void) dynamic_cast<B&>(p);
			std::cout << "Identified class B!" << std::endl;
		} catch (std::exception &e1) {
			(void) e1;
			try {
				(void) dynamic_cast<C&>(p);
				std::cout << "Identified class C!" << std::endl;
			} catch (std::exception &e2) {
				(void) e2;
				std::cout << "What the heck?" << std::endl;
			}
		}
	}
}

int main() {
	std::srand(std::time(NULL));

	Base *randomClass = generate();

	identify(randomClass);
	identify(*randomClass);
}