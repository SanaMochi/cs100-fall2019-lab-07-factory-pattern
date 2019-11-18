#ifndef _Abs_
#define _Abs_

//#include "base.hpp"
#include "decorator.hpp"
#include <cmath>

class Abs : public Decorator {
	public:
	
	Abs(Base* c) : Decorator(c){
		this->c = c;
	}
	
	virtual double evaluate() {
		return std::abs(this->c->evaluate());
	}
};

#endif //_Abs_
