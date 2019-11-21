#include <iostream>
#include "factory.hpp"

int main(int argc, char** argv) {

	Factory* f = new Factory();
	f->parse(argv, argc);
	std::cout << f->getResult() << std::endl;
	
	return 0;
}
