/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:46:32 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 18:51:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern ( void );
		Intern ( Intern const & src );
		Intern &operator=( Intern const & rhs );
		~Intern ( void );
		AForm *makeForm(std::string const &formName, std::string const &target);
		AForm *makeShrubberyCreationForm(std::string const &target);
		AForm *makeRobotomyRequestForm(std::string const &target);
		AForm *makePresidentialPardonForm(std::string const &target);
		class FormDoesntExistException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string _formNames[3];
		AForm *(Intern::*_makeForm[3])(std::string const &target);
};

#endif