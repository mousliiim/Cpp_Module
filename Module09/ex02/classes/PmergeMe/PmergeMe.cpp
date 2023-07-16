/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:50:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/16 23:34:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe ( char **argv )
{
	if (!*argv || !argv)
		ERROR_PTR_NULL;

	std::vector <int> cpydisplay;
	for (int i = 1; argv[i]; i++)
		cpydisplay.push_back(std::atoi(argv[i]));
	display(cpydisplay, true);


	_time._vecBegin = std::clock();
	for (int i = 1; argv[i]; i++)
		_vector.push_back(std::atoi(argv[i]));
	merge_insert(_vector.begin(), _vector.end());
	_time._vecEnd = std::clock();

	_time._dequeBegin = std::clock();
	for (int i = 1; argv[i]; i++)
		_deque.push_back(std::atoi(argv[i]));
	merge_insert(_deque.begin(), _deque.end());
	_time._dequeEnd = std::clock();

	display(_deque, false);
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _time._vecEnd - _time._vecBegin << " us\n";
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << _time._dequeEnd - _time._dequeBegin  << " us\n";
}

PmergeMe::~PmergeMe ( void ) { }


PmergeMe::PmergeMe	( PmergeMe const &src )
{
	*this = src;
}

PmergeMe	&PmergeMe::operator=( PmergeMe const &src )
{
	if (this != &src)
	{
		_vector = src._vector;
		_deque = src._deque;
		_time = src._time;
	}
	return *this;
}

void	PmergeMe::merge_insert(it_vec first, it_vec last)
{
	if (std::distance(first, last) <= 1)
		return ;
	it_vec middle = first;
	std::advance(middle, (std::distance(first, last) / 2));
	merge_insert(first, middle);
	merge_insert(middle, last);
	std::inplace_merge(first, middle, last);
}

void	PmergeMe::merge_insert(it_deque first, it_deque last)
{
	if (std::distance(first, last) <= 1)
		return ;
	it_deque middle = first; 
	std::advance(middle, (std::distance(first, last) / 2));
	merge_insert(first, middle);
	merge_insert(middle, last);
	std::inplace_merge(first, middle, last);
}

std::vector <int>	&PmergeMe::getVector ( void )
{
	return (_vector);
}

std::deque <int>	&PmergeMe::getDeque ( void )
{
	return (_deque);
}

void PmergeMe::setVector ( std::vector <int> &vector )
{
	_vector = vector;
}

void PmergeMe::setDeque ( std::deque <int> &deque )
{
	_deque = deque;
}

template <typename T>
void display (const T &container, bool before)
{
	before ? std::cout << "Before : " : std::cout << "After : ";
	
	for (unsigned int i = 0; i < container.size(); i++)
	{
		if (i == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

bool parsingArgument(char **argv, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (argv[i][0] == '\0')
			ERROR_NOT_INT;
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			if (argv[i][1] == '\0')
				ERROR_NOT_INT;
			for (int j = 1; argv[i][j]; j++)
				if (!isdigit(argv[i][j]))
					ERROR_NOT_INT;
		}
		else
		{
			for (int j = 0; argv[i][j]; j++)
				if (!isdigit(argv[i][j]))
					ERROR_NOT_INT;
		}
	} 
	for (int i = 1; i < n; i++)
		if (std::atol(argv[i]) > INT_MAX || std::atol(argv[i]) < INT_MIN)
			ERROR_INT_MAX_MIN;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (std::atol(argv[i]) == std::atol(argv[j]))
				ERROR_TWICE_NB;
	}
	for (int i = 2; i < n; i++)
	{
        if (std::atol(argv[i]) < std::atol(argv[i - 1]))
			return false;
	}
    return true;
}