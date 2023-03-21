#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

std::map<string, string> get_data(std::string file)
{
    std::ifstream csv(file);

    if (!file.is_open())
	{
        std::cout << "Could not open CSV file " << cvs << std::endl;
        return;
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