#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, float> map;

	void parseData(std::ifstream &data);
	void parseInput(std::ifstream &input);
	void showRateByDate(std::string const &date, std::string const &val);
public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream &file);
	~BitcoinExchange();

	BitcoinExchange  &operator=(BitcoinExchange const &rhs);

	void showMap();
};
