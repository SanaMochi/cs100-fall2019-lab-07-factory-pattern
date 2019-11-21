#include <iostream>
#include "factory.hpp"

int main(int argc, char** argv) {

	Factory* f = new Factory();
	f->parse(argv, argc);
	std::cout << "Double: " << f->getResultNum() << std::endl;
	std::cout << "String: " << f->getResultStr() << std::endl;
	
	return 0;
}
