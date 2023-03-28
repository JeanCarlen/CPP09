#include "BitcoinExchange.hpp"

int btc::get_data(void)
{
    std::ifstream file("data.csv");
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    while (std::getline(file, line))
    {
        std::stringstream lineStream(line);
        std::string dateStr;
        double value;
        std::getline(lineStream, dateStr, ',');
        lineStream >> value;
        data[dateStr] = value;
    }

    file.close();

    return 0;
}

double btc::get_date(std::string date)
{
	std::map<std::string, double>::iterator itr = this->data.begin();
	std::string	closest = itr->first;
	while(itr != this->data.end())
	{
		if(date > closest)
			itr++;
		if(date == closest)
			return(this->data.find(closest)->second);
		if (date < closest)
			return(this->data.find(closest)->second);
		closest = itr->first;
	}
	return(this->data.find(closest)->second);
}

int btc::convert(char *file, btc &btc)
{
    std::ifstream input;
    std::string line;
    std::string date;
    std::string value;
    double result;

    input.open(file);
    if (!input)
    {
        std::cout << "Unable to open " << file << std::endl;
        return (1);
    }
    std::getline(input, line);
    while (std::getline(input, line))
    {
        date = line.substr(0,10);
		if (is_date_valid(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
        value = line.substr(13,5);
		if(value == "")
		{
			std::cout << "Error: didn't find a number => " << date << std::endl;;
			continue;
		}
		else
		{
			result = std::stod(value);
			if(result < 0)
			{
				std::cout << "Error: not a positive number.\n";
				continue;
			}
			if(result > 1000)
			{
				std::cout << "Error: too large a number.\n";
				continue;
			}
			result = result * btc.get_date(date);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
    }
    input.close();
    return (0);
}

int	is_date_valid(std::string date)
{
	int y,m,d;
	std::string tmp;

	y = std::stoi(date.substr(0,4));
	m = std::stoi(date.substr(5,2));
	d = std::stoi(date.substr(8,2));
	if(y > 9999)
		return (1);
	if(m > 12 )
		return (1);
	if(d > 31 )
		return (1);
	return(0);
}

btc::btc(void)
{
    std::cout << "default constructor\n";
}

btc::~btc(void)
{
    std::cout << "default destructor\n";
}

/*
2 fichiers :
	data.csv =>ce dernier contient des strings avec "data,ratio"
	test.txt =>ce dernier contient des strings avec "date | value"

ouvrir/lire le data.cvs et le store dans un std::map ou un container.
on lit ligne par ligne le fichier .txt
et on compare la date de la ligne du .txt avec celles
qui sont les plus proches dans le container remplis par data.csv
ex:
	.txt = "2011-01-03 | 3"
	si la date n'existe pas dans le container, il faut prendre la date la plus proche AVANT
	la date du .txt

	puis on multiplie la value du .txt par le ratio du container

il doit y'avoir des checks d'erreurs pour:
	chiffre neg
	chiffre < 1000
	si la date n'est pas possible (ex 2011-100-100)

il faut print chaque lignes après qu'elle ai été check puis comparée.



*/