#ifndef _Floor_
#define _Floor_

//#include "base.hpp"
#include "decorator.hpp"
#include <cmath>

class Floor : public Decorator {
	public:
	
	Floor(Base* c) : Decorator(c){
		this->c = c;
	}
	
	virtual double evaluate() {
		return floor(this->c->evaluate());
	}
};

#endif //_Floor_
