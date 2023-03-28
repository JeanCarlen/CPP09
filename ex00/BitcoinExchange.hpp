#include <iostream>
#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class btc
{
    private:
        std::map<std::string, double> data;

    public:
        int get_data(void);
        int convert(char *input, btc &btc);
        double get_date(std::string date);
        btc();
        ~btc();
};

int	is_date_valid(std::string date);
#endif