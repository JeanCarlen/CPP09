#include "RPN.hpp"

int RPN::PrintStack(std::stack<double> &calcStack)
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

void RPN::calcul(std::stack<double> &calcStack, char *input)
{
	int i, x, z;

	i = 0;

	while(input[i])
	{
		if(std::isspace(input[i]))
		{
			i++;
			continue;
		}
		if(std::isdigit(input[i]))
		{
			this->calcStack.push(input[i] - '0');
			//std::cout << "stack is : " << input[i] - '0' << std::endl;
			i++;
			continue;
		}
		if(is_op(input[i]))
		{
			if (calcStack.size() < 2)
			{
				std::cout << "ERROR in calculation\n";
				return;
			}
			//std::cout << "input is : " << input[i] << std::endl;
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
			//std::cout << "we are at " << calcStack.top() << "\n";
			i++;
			continue;
		}
		std::cout << "this signe is not known : " << input[i];
		return;
	}
	if(calcStack.size() > 0)
		std::cout << calcStack.top();
	std::cout << std::endl;
}

int is_op(char op)
{
	if (op == '+' || op == '-' || op == '/' || op == '*')
		return (1);
	return (0);
}