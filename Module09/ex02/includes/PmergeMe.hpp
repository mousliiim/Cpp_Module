/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:39:06 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/16 23:33:45 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <math.h>
# include <limits.h>
# include <string.h>
# include <ctime>
# include <vector>
# include <deque>

# define WHITE_BOLD "\033[1;37m"
# define RESET "\033[0m"

# define ERROR_NB_ARGS throw std::invalid_argument(WHITE_BOLD "Error :: " RESET "Need 2 Arguments minimum")
# define ERROR_NOT_INT throw std::invalid_argument(WHITE_BOLD "Error :: " RESET "Arguments must be integers")
# define ERROR_ALREADY_SORTED throw std::invalid_argument(WHITE_BOLD "Error :: " RESET "Arguments are already sorted")
# define ERROR_INT_MAX_MIN throw std::invalid_argument(WHITE_BOLD "Error :: " RESET "Arguments must be between INT_MIN and INT_MAX")
# define ERROR_PTR_NULL throw std::invalid_argument(WHITE_BOLD "Error :: " RESET "Pointer is NULL")
# define ERROR_TWICE_NB throw std::invalid_argument(WHITE_BOLD "Error :: " RESET "Can't have the same argument twice");

typedef std::vector <int>::iterator it_vec;
typedef std::deque <int>::iterator it_deque;

typedef struct s_time
{
	std::clock_t				_vecBegin;
	std::clock_t				_dequeBegin;
	std::clock_t				_vecEnd;
	std::clock_t				_dequeEnd;
} t_time;

class PmergeMe
{
	public:
		PmergeMe	( char **argv );
		~PmergeMe	( void );
		PmergeMe	( PmergeMe const &src );
		PmergeMe	&operator=( PmergeMe const &src );

		void	merge_insert(it_vec first, it_vec last);
		void	merge_insert(it_deque first, it_deque last);
		
		std::vector <int>	&getVector ( void );
		std::deque <int>	&getDeque ( void );
		void				 setVector ( std::vector <int> &vector );
		void				 setDeque ( std::deque <int> &deque );

	private:
		t_time				_time;
		std::deque <int>	_deque;
		std::vector <int>	_vector;
};

template <typename T>
void display (const T &container, bool before);

bool parsingArgument(char **argv, int n);

#endif