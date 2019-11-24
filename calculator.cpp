#include <iostream>
#include "factory.hpp"

int main(int argc, char** argv) {
	//char* c[] = {"test", "25/6*9"};
	Factory* f = new Factory();
	//f->parse(c, 2);
	f->parse(argv, argc);
	std::cout << "Double: " << f->getResultNum() << std::endl;
	std::cout << "String: " << f->getResultStr() << std::endl;
	
	return 0;
}
