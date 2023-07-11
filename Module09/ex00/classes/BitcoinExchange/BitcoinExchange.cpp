/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 02:43:41 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/11 18:45:56 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange ( void ) { }

BitcoinExchange::BitcoinExchange ( char *inputFile )
{
	_inputFile = inputFile;
	parsingData();
	parsingInput();
	
}

BitcoinExchange::BitcoinExchange ( BitcoinExchange const &src )
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator= ( BitcoinExchange const &src)
{
	if (this != &src)
	{
		(void)src;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange ( void ) { }

void BitcoinExchange::parsingData ( void )
{
	std::ifstream data("files/data.csv");
	std::string line;

	if (!data.is_open())
		throw std::invalid_argument(WHITE_B "Error :: " RESET "Can't open file /files/data.csv");
	std::getline(data, line);
	line == "date,exchange_rate" ? true : throw std::invalid_argument(WHITE_B "Error :: " RESET "Wrong file format of csv");
	while (std::getline(data, line))
		checkDataLine(line) ? true : throw std::invalid_argument(WHITE_B "Error :: " RESET "Wrong file format of csv");
	data.close();
}

bool  BitcoinExchange::checkDataLine (std::string const &line)
{
	std::string data[4];
	int min[3] = {2009, 1, 1};
	int max[3] = {2023, 12, 31};
	int value[4];

	std::stringstream ss(line);

	std::getline(ss, data[YEAR], '-');
	std::getline(ss, data[MONTH], '-');
	std::getline(ss, data[DAY], ',');
	for (int i = 0; i < 3; i++)
		value[i] = std::atol(data[i].c_str());
	if (data[YEAR].size() != 4 || data[MONTH].size() != 2 || data[DAY].size() != 2)
		return false;

	if (value[MONTH] < 8)
		max[DAY] = (value[MONTH] % 2 == 0 ? 30 : 31);
	else if (value[MONTH] > 8)
		max[MONTH] = (value[MONTH] % 2 ? 30 : 31);
	if (value[1] == 2)
		max[MONTH] = (value[YEAR] % 4) ? 28 : 29;

	for (int i = 0; i < 3; i++)
	{
		if (data[i].empty() || data[i].find_first_not_of("0123456789") != std::string::npos || value[i] < min[i] || value[i] > max[i])
			return false;
	}

	ss >> data[PRICE];
	if (ss.fail() || !ss.eof() || data[PRICE].find_first_not_of("0123456789.") != std::string::npos || data[PRICE].empty() || std::atof(data[PRICE].c_str()) < 0)
		return false;
	_mDatePrice.insert(std::pair<std::string, double>(line.substr(0, 10), std::atof(data[PRICE].c_str())));
	// std::cout << _mDatePrice[line.substr(0, 10)] << std::endl;
	return true;
}

// NEED TO PARSE THE EXCHANGE RATE
short BitcoinExchange::checkDataInput ( std::string const &line )
{
	std::string data[4];
	int min[3] = {2009, 1, 1};
	int max[3] = {2023, 12, 31};
	int value[4];

	std::stringstream ss(line);

	std::getline(ss, data[YEAR], '-');
	std::getline(ss, data[MONTH], '-');
	std::getline(ss, data[DAY], ' ');
	for (int i = 0; i < 3; i++)
		value[i] = std::atol(data[i].c_str());
	if (data[YEAR].size() != 4 || data[MONTH].size() != 2 || data[DAY].size() != 2)
		return ERROR_DATE;
	if (value[MONTH] < 8)
		max[DAY] = (value[MONTH] % 2 == 0 ? 30 : 31);
	else if (value[MONTH] > 8)
		max[MONTH] = (value[MONTH] % 2 ? 30 : 31);
	if (value[1] == 2)
		max[MONTH] = (value[YEAR] % 4) ? 28 : 29;

	for (int i = 0; i < 3; i++)
	{
		if (data[i].empty() || data[i].find_first_not_of("0123456789") != std::string::npos || value[i] < min[i] || value[i] > max[i])
			return ERROR_DATE;
	}

	// if (_mDatePrice.find(line.substr(0, 10)) == _mDatePrice.end())
	// 	return ERROR_NOT_FOUND;
	return OK;
}

void BitcoinExchange::parsingInput ( void )
{
	std::ifstream input(_inputFile);
	std::string line;

	if (!input.is_open())
		throw std::invalid_argument(WHITE_B "Error :: " RESET "Can't open file (Input file)");
	std::getline(input, line);
	line == "date | value" ? true : throw std::invalid_argument(WHITE_B "Error :: " RESET "Wrong file format of input");
	while (std::getline(input, line))
		printResult(line, checkDataInput(line));
	input.close();
}

// $> ./btc
// Error: could not open file.
// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
// $>

void BitcoinExchange::printResult ( std::string const &line, short error )
{
	if (error == OK)
	{
		std::cout << line << " => " << _mDatePrice[line.substr(0, 10)] << std::endl;
	}
	if (error == ERROR_DATE)
		std::cerr << "Error: bad input => " << line << std::endl;
}
