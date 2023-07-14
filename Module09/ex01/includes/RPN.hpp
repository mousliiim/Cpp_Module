/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:09:14 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/14 02:02:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <math.h>
# include <string.h>
# include <stack>

# define WHITE_BOLD "\033[1;37m"
# define RESET "\033[0m"

# define ERROR 1
# define SUCCESS 0

class RPN
{
	public:
		RPN ( void );
		RPN ( std::string const &arg );
		RPN ( RPN const &src );
		RPN &operator= ( RPN const &src );
		~RPN ( void );

		void	parsing ( void );
		void	calculate ( void );
	private:
		std::string		 _expression;
		std::stack <int> _sNumbers;
};

#endif