/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:08:53 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/14 02:03:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN ( void ) { }

RPN::RPN ( std::string const &arg ) : _expression(arg)
{
	parsing();
	calculate();
}

RPN::RPN ( RPN const &src )
{
	*this = src;
}

RPN &RPN::operator= ( RPN const &src )
{
	if (this != &src)
	{
		_expression = src._expression;
		_sNumbers = src._sNumbers;
	}
	return *this;
}

RPN::~RPN ( void ) { }

void RPN::parsing ( void )
{
	int countNumber = 0;
	int countOperator = 0;
	
	_expression.find_first_not_of("0123456789+/-* \t") != std::string::npos ? throw std::invalid_argument(WHITE_BOLD "Error: " RESET "Expression have to be only numbers and operators") : true;
	for (int i = 0; _expression[i]; i++)
	{
		while (_expression[i] == ' ' || _expression[i] == '\t')
			i++;
		if (!std::isdigit(_expression[i]) && !strchr("+-/*", _expression[i]))
			throw std::invalid_argument(WHITE_BOLD "Error: " RESET "Expression have to be only numbers and operators");
		if (std::isdigit(_expression[i]))
			countNumber++;
		else if (strchr("+-/*", _expression[i]))
			countOperator++; 
	}
	if (countNumber - countOperator != 1 || (countNumber > 0 && countOperator == 0))
		throw std::invalid_argument(WHITE_BOLD "Error: " RESET "Expression is not valid");
}

void RPN::calculate ( void )
{
	for (int i = 0; _expression[i]; i++)
	{
		while (_expression[i] == ' ' || _expression[i] == '\t')
			i++;
		if (std::isdigit(_expression[i]))
		{
			int nb = _expression[i] - '0';
			_sNumbers.push(nb);
		}
		else if (strchr("+-/*", _expression[i]))
		{
			if (_sNumbers.size() < 2)
				throw std::invalid_argument(WHITE_BOLD "Error: " RESET "Expression is not valid");
			int nb1 = _sNumbers.top();
			_sNumbers.pop();
			int nb2 = _sNumbers.top();
			_sNumbers.pop();
			if (_expression[i] == '+')
				_sNumbers.push(nb2 + nb1);
			else if (_expression[i] == '-')
				_sNumbers.push(nb2 - nb1);
			else if (_expression[i] == '*')
				_sNumbers.push(nb2 * nb1);
			else if (_expression[i] == '/')
			{
				if (nb1 == 0)
					throw std::invalid_argument(WHITE_BOLD "Error: " RESET "Division by 0 is not valid");
				_sNumbers.push(nb2 / nb1);
			}
		}
	}
	if (_sNumbers.size() != 1)
		throw std::invalid_argument(WHITE_BOLD "Error: " RESET "Expression is not valid");
	std::cout << _sNumbers.top() << std::endl;
}