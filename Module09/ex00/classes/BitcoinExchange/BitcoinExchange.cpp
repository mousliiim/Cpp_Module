/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 02:43:41 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/12 18:48:49 by mmourdal         ###   ########.fr       */
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
		!checkDataLine(line, true) ? true : throw std::invalid_argument(WHITE_B "Error :: " RESET "Wrong file format of csv");
	data.close();
}

short  BitcoinExchange::checkDataLine (std::string const &line, bool checkData)
{
	std::string data[4];
	int min[3] = {2009, 1, 1};
	int max[3] = {2023, 12, 31};
	int value[4];

	std::stringstream ss(line);

	std::getline(ss, data[YEAR], '-');
	std::getline(ss, data[MONTH], '-');
	if (checkData)
		std::getline(ss, data[DAY], ',');
	else
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

	if (checkData)
	{
		ss >> data[PRICE];
		if (ss.fail() || !ss.eof() || data[PRICE].find_first_not_of("0123456789.") != std::string::npos || data[PRICE].empty() || std::atof(data[PRICE].c_str()) < 0)
			return ERROR_PRICE;
		_mDatePrice.insert(std::pair<std::string, double>(line.substr(0, 10), std::atof(data[PRICE].c_str())));
	}
	else
	{
		ss >> data[3];
		if (data[3].find_first_not_of("|") != std::string::npos || data[3].empty())
			return ERROR_FORMAT;
		ss >> data[RATIO];
		if (std::atof(data[RATIO].c_str()) > INT_MAX)
			return ERROR_TOO_LARGE;
		if (std::atof(data[RATIO].c_str()) < 0)
			return ERROR_TOO_SMALL;
		if (ss.fail() || !ss.eof() || data[RATIO].find_first_not_of("0123456789.") != std::string::npos || data[RATIO].empty())
			return ERROR_FORMAT;
		_ratio = std::atof(data[RATIO].c_str());
	}
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
		printResult(line, checkDataLine(line, false));
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
	size_t check = _mDatePrice.count(line.substr(0, 10));
	if (!check)
	{
		error = ERROR_NOT_FOUND;
		std::map<std::string, double>::iterator map_it = _mDatePrice.begin();
		std::string tmp = map_it->first;
		for (; map_it != _mDatePrice.end(); map_it++)
		{
			if (map_it->first > tmp && map_it->first < line.substr(0, 10))
				tmp = map_it->first;
		}
		std::cout << " DATE LOWER THAN " << line.substr(0, 10) << " => " << tmp << " = " << _mDatePrice[tmp] * _ratio << std::endl;
	}
	switch (error)
	{
		case OK:
			std::cout << line.substr(0, 10) << " => "  << _ratio << " = " << _mDatePrice[line.substr(0, 10)] * _ratio << std::endl;
			break;
		case ERROR_NOT_FOUND:
			// FIX MEEEEE
			// std::cout << tmp << " => "  << _ratio << " = " << _mDatePrice[tmp] * _ratio << std::endl;
			break;
		case ERROR_DATE:
			std::cout << "Error: bad input => " << line << std::endl;
			break;
		case ERROR_TOO_SMALL:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case ERROR_TOO_LARGE:
			std::cout << "Error: too large a number." << std::endl;
			break;
		case ERROR_FORMAT:
			std::cout << "Error: bad input => " << line << std::endl;
			break;
	}
}
