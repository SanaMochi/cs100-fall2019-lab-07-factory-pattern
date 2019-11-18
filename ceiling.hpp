#ifndef _Ceiling_
#define _Ceiling_

#include "decorator.hpp"
#include <cmath>

class Ceiling : public Decorator {
	public:
	Ceiling(Base* c) : Decorator(c){
		this->c = c;
	}
	
	virtual double evaluate() {
		return ceil(this->c->evaluate());
	}
};

#endif //_Ceiling_
