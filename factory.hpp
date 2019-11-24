#ifndef _FACTORY_
#define _FACTORY_
#include <string>
#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"

class Factory{
	double resultNum = 0.0;
	std::string resultStr;
	
	Add* addFactory(int firstSignIndex, std::string parsedExpression) {
			std::string operator1 = "";
			std::string operator2 = "";
			double oper1;
			double oper2;
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
			return add;
	}

	Sub* subFactory(int firstSignIndex, std::string parsedExpression) {
			std::string operator1 = "";
			std::string operator2 = "";
			double oper1;
			double oper2;
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
			Sub* sub = new Sub(op1, op2);
			return sub;
	}

	Mult* multFactory(int firstSignIndex, std::string parsedExpression) {
			std::string operator1 = "";
			std::string operator2 = "";
			double oper1;
			double oper2;
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
			Mult* mult = new Mult(op1, op2);
			return mult;
	}

	Div* divFactory(int firstSignIndex, std::string parsedExpression) {
			std::string operator1 = "";
			std::string operator2 = "";
			double oper1;
			double oper2;
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
			Div* div = new Div(op1, op2);
			return div;
	}
	public:
	double getResultNum() {
		return this->resultNum;
	}
	std::string getResultStr() {
		return this->resultStr;
	}
	
	Base* parse(char** input, int length) {
			std::string expression = input[1];
			std::string parsedExpression = "";
			std::string substr2 = "";
			
			bool firstSign = false;
			char firstSign1;
			int firstSignIndex = 0;
			
			do {
			
			parsedExpression = "";
			substr2 = "";

			firstSign = false;
			firstSignIndex = 0;
//changed this 0 -> 1 to ignore sign bit if there is one
			for (int i = 1; i < expression.size(); i++) {
				if ((expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/') && firstSign == false) {
					firstSign = true;
					firstSign1 = expression.at(i);
//					std::cout << expression.at(i) << std::endl;
					firstSignIndex = i;
				}
				else if ((expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/') && firstSign == true) {
					parsedExpression = expression.substr(0, i);
					if (i != expression.at(expression.size() - 1)) {
						substr2 = expression.substr(i, expression.size() - 1); 
					}
				}
				else if (firstSign == true) {
					parsedExpression = expression;
				}
			}
//			std::cout << expression << std::endl;
//			std::cout << parsedExpression << std::endl;
//			std::cout << substr2 << std::endl;

			
			std::string res;
			if (firstSign1 == '+') {
				Add* sum = addFactory(firstSignIndex, parsedExpression);
				res =  std::to_string(sum->evaluate());
				expression = res + substr2;
				resultNum = sum->evaluate();
				resultStr = sum->stringify();
//				std::cout << sum->evaluate() << std::endl;
			}
			else if (firstSign1 == '-') {
				Sub* diff = subFactory(firstSignIndex, parsedExpression);
				res =  std::to_string(diff->evaluate());
				expression = res + substr2;
				resultNum = diff->evaluate();
				resultStr = diff->stringify();
//				std::cout << diff->evaluate() << std::endl;
			}
			else if (firstSign1 == '*') {
				Mult* prod = multFactory(firstSignIndex, parsedExpression);
				res =  std::to_string(prod->evaluate());
				expression = res + substr2;
				resultNum = prod->evaluate();
				resultStr = prod->stringify();
//				std::cout << prod->evaluate() << std::endl;
			}
			else if (firstSign1 == '/') {
				Div* fac = divFactory(firstSignIndex, parsedExpression);
				res =  std::to_string(fac->evaluate());
				expression = res + substr2;
				resultNum = fac->evaluate();
				resultStr = fac->stringify();
//				std::cout << fac->evaluate() << std::endl;
			}
//			std::cout << expression << std::endl;
		} while (substr2 != "");
		Op* op = new Op(resultNum);
		return op;
	}
};
#endif
