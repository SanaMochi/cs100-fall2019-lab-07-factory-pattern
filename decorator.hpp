#ifndef __DEC_HPP__
#define __DEC_HPP__
#include "base.hpp"

class Decorator: public Base{
	protected:
	
	
	public:
	Base* c;
	Decorator(Base* b){this->c = b;}
	
	virtual double evaluate(){
		return this->c->evaluate();
	}
	
    virtual std::string stringify(){
		return this->c->stringify();
	}
	/*
	void set_child(Base * c){
		this->c = c;
	}*/
};
#endif
