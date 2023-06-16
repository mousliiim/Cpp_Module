/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:46 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 22:08:32 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <exception>
# include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm ( void );
		RobotomyRequestForm ( RobotomyRequestForm const & src );
		~RobotomyRequestForm ( void );
		RobotomyRequestForm &operator=( RobotomyRequestForm const & rhs );
};

#endif