#include "RPN.hpp"

int RPN::get_data(char *input)
{
	std::stack<int> calcStack;
	int i = 0;

	while(input[i])
	{
		if(std::isdigit(input[i]))
		{
//			std::cout << input[i] << std::endl;
			this->calcStack.push(input[i] - '0');
		}
		i++;
	}
	return(1);
}

int RPN::PrintStack(std::stack<int> &calcStack)
{
	if (calcStack.empty())
		return(0);
	int x = calcStack.top();
	calcStack.pop();
	PrintStack(calcStack);
	std::cout << x << "\n";
	calcStack.push(x);
	return(1);
}

void RPN::calcul(std::stack<int> &calcStack, char *input)
{
	int i, x, z;

	i = 0;
	while(input[i])
	{
		if(std::isdigit(input[i]) || std::isspace(input[i]))
			i++;
		if(is_op(input[i]))
		{
			// std::cout << input[i] << std::endl;
			z = calcStack.top();
			calcStack.pop();
			x = calcStack.top();
			calcStack.pop();
			if (input[i] == '+')
				calcStack.push(x + z);
			if (input[i] == '-')
				calcStack.push(x - z);
			if (input[i] == '*')
				calcStack.push(x * z);
			if (input[i] == '/')
				calcStack.push(x / z);
			// std::cout << "we are at " << calcStack.top() << "\n";
		}
		i++;
	}
	std::cout << calcStack.top();
	std::cout << std::endl;
}

int is_op(char op)
{
	if (op == '+' || op == '-' || op == '/' || op == '*')
		return (1);
	return (0);
}