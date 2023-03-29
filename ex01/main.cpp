#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN RPN;
	if (ac < 2)
		std::cout << "no calculs found\n";
	else
		RPN.calcul(RPN.calcStack, av[1]);
	return(0);
}