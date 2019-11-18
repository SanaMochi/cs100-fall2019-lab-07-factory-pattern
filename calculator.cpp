#include <iostream>
#include <string>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
//#include "factory.hpp"

int main(int argc, char** argv) {
	
		std::string expression = argv[1];
		std::string parsedExpression = expression;
		bool firstSign = false;
		char firstSign1;
		int firstSignIndex = 0;
		int sizeToErase = 0;
		for (int i = 0; i < expression.size(); i++) {
			if ((expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/') && firstSign == false) {
				firstSign = true;
				firstSign1 = expression.at(i);
				std::cout << expression.at(i) << std::endl;
				firstSignIndex = i;
			}
			else if ((expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/') && firstSign == true) {
				//std::string parsedExpression = expression;
				sizeToErase = expression.size() - i;
				parsedExpression.erase(i, sizeToErase);
			}
		}
		std::cout << expression << std::endl;
		std::cout << parsedExpression << std::endl;

		std::string operator1 = "";
		std::string operator2;
		double oper1;
		double oper2;
		if (firstSign1 == '+') {
			for (int i = 0; i < firstSignIndex; i++) {
				operator1 += parsedExpression.at(i);
				oper1 = std::atof(operator1.c_str());
			}
			for (int i = firstSignIndex + 1; i < parsedExpression.size(); i++) {
				operator2 += parsedExpression.at(i);
				oper2 = std::atof(operator2.c_str());
				
			}
			Op* op1 = new Op(oper1);
			Op* op2 = new Op(oper2);
			Add* add = new Add(op1, op2);
//			std::cout << oper1 << std::endl;
//			std::cout << op1->evaluate() << std::endl;
//			std::cout << op2->evaluate() << std::endl;
			std::cout << add->evaluate() << std::endl;
		}
		
	return 0;
}
