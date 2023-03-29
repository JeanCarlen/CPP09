#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include<iomanip>

class RPN
{
	public:
		std::stack<double> calcStack;
		int PrintStack(std::stack<double> &calcStack);
		void calcul(std::stack<double> &calcStack, char *input);
};
int is_op(char op);

#endif