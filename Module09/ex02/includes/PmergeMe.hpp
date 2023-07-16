/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:39:06 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/16 02:50:24 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <math.h>
# include <string.h>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe ( void );
		~PmergeMe ( void );
		PmergeMe ( PmergeMe const &src );
		PmergeMe & operator=( PmergeMe const &src );
		bool    isSorted(std::vector<int> &vec);
		bool    isSorted(std::deque<int> &vec);
		void	mergeSort(std::vector<int> &vec);
		void	mergeSort(std::deque<int> &vec);
	
	private:
		std::deque <int> _deque;
		std::vector <int> _vector;
};

#endif