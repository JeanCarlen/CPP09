#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	btc		btc;
	(void)ac;
    if (btc.get_data())
        return (1);
    btc.convert(av[1], btc);
    return (0);
}