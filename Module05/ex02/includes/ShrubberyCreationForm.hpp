/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:46:05 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 22:08:43 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <exception>
# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm ( void );
		ShrubberyCreationForm ( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm ( void );
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const & rhs );
};

#endif