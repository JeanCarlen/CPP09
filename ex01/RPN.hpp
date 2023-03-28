#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include<iomanip>

class RPN
{
	private:
	public:
		std::stack<int> calcStack;
		int get_data(char *input);
		int PrintStack(std::stack<int> &calcStack);
		void calcul(std::stack<int> &calcStack, char *input);
};
int is_op(char op);

#endif