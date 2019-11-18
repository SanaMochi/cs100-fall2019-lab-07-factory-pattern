#include "decorator.hpp"

class Paren: public Decorator{
	//std::string string = "";
	/*
	Paren(std::string str){
		this->string = str;
	}*/
	Decorator * d;
	public:
	Paren(Decorator* d) : Decorator(d){this->d = d;};
	
	//Paren(Base* b){this->c = b;}
	
	virtual std::string stringify(){
		return "(" + d->c->stringify() + ")";
	}
};
