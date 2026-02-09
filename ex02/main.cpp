#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int random = rand() % 3;
	
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {
	}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {

	}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) {

	}
}

int main(void) 
{
	srand(time(NULL));

	std::cout << " 10 random objects:" << std::endl;
	for (int i = 0; i < 10; i++) {
		Base *obj = generate();
		std::cout << "Pointer identify: ";
		identify(obj);
		std::cout << "Reference identify: ";
		identify(*obj);
		delete (obj);
		std::cout << std::endl;
	}

	return (0);
}
