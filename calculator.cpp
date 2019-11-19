#include <iostream>
#include <string>
#include "add.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "op.hpp"

int main(int argc, char *argv[]){
	int pos = 0;
	int temp = 0;
	int num1 = 0;
	int num2 = 0;
	//Op* number;
	std::string tempstr ;
	std::string cuts; 
	std::string rest;
	std::string operation = "";
	std::string s = argv[1];
	
	do{
		std::cout << s << std::endl;
		pos = 0;
		//int prev = s.size();
		//for(int i = 0; i < 2; i++){
			if(s.find("+", pos) != -1 && s.find("+", pos) < pos){
				pos = s.find("+");
				operation = "+";
				//prev = pos;
				std::cout << "\npos+: " << pos;
			}else if(s.find("-", pos) != -1 && s.find("-", pos) < pos){
				pos = s.find("-");
				operation = "-";
				//prev = pos;
				std::cout << "\npos-: " << pos;
			}else if(s.find("*", pos) != -1 && s.find("*", pos) < pos+1){
				pos = s.find("*", pos);
				operation = "*";
			}else if(s.find("/", pos) != -1 && s.find("/", pos) < pos+1){
				pos = s.find("/", pos);
				operation = "/";
			}
		//}
		std::cout << "\npos: " << pos;
		cuts = s.substr(0, pos);
		rest = s.substr(pos, -1);
		std::cout << "\ncuts: " << cuts << "rest: " << rest;
		
		if(cuts.find("+")!= -1){
			operation = "+";
		}
		if(cuts.find("-")!= -1){
			operation = "-";
		}
		if(cuts.find("*")!= -1){
			operation = "*";
		}
		if(cuts.find("/")!= -1){
			operation = "/";
		}
		tempstr = cuts.substr(0,cuts.find(operation));
		num1 = atof(tempstr.c_str());
		num2 = atof(cuts.substr(cuts.find(operation)+1, -1).c_str());
		std::cout << "\nnum 1: " << num1;
		std::cout << "\nnum 2: " << num2;
		if(operation == "+"){
			std::cout << "\nyou should add";
			Op* t1 = new Op(num1);
			Op* t2 = new Op(num2);
			Add* tempOp = new Add(t1, t2);
			std::cout << tempOp->evaluate();
		}
		if(operation == "-"){
			std::cout << "\nyou should subrtact";
			Op* t1 = new Op(num1);
			Op* t2 = new Op(num2);
			Sub* tempOp = new Sub(t1, t2);
			std::cout << tempOp->evaluate();
		}
		if(operation == "*"){
			std::cout << "\nyou should multiply";
			Op* t1 = new Op(num1);
			Op* t2 = new Op(num2);
			Mult* tempOp = new Mult(t1, t2);
			std::cout << tempOp->evaluate();
		}
		if(operation == "/"){
			std::cout << "\nyou should divide";
			Op* t1 = new Op(num1);
			Op* t2 = new Op(num2);
			Div* tempOp = new Div(t1, t2);
			std::cout << tempOp->evaluate();
		}
		std::cout << std::endl;
		s = rest;
	 pos = 0;
	temp = 0;
	num1 = 0;
	num2 = 0;
	break;
		}while(rest != "");
return 0;	
}
