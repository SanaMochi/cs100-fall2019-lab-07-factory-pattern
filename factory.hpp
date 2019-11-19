#include <string>

Base* parse(char** input, int length) {
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
				sizeToErase = expression.size() - i;
				parsedExpression.erase(i, sizeToErase);
			}
		}
		std::cout << expression << std::endl;
		std::cout << parsedExpression << std::endl;

		if (firstSign1 == '+') {
			Add* sum = addFactory(firstSignIndex, parsedExpression);
//			std::cout << sum->evaluate() << std::endl;
		}
		else if (firstSign1 == '-') {
			Sub* diff = subFactory(firstSignIndex, parsedExpression);
//			std::cout << diff->evaluate() << std::endl;
		}
		else if (firstSign1 == '*') {
			Mult* prod = multFactory(firstSignIndex, parsedExpression);
//			std::cout << prod->evaluate() << std::endl;
		}
		else if (firstSign1 == '/') {
			Div* fac = divFactory(firstSignIndex, parsedExpression);
//			std::cout << fac->evaluate() << std::endl;
		}
}

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
