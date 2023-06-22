/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:02:58 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 18:50:57 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern ( void )
{
	_formNames[0] = "ShrubberyCreationForm";
	_formNames[1] = "RobotomyRequestForm";
	_formNames[2] = "PresidentialPardonForm";
	_makeForm[0] = &Intern::makeShrubberyCreationForm;
	_makeForm[1] = &Intern::makeRobotomyRequestForm;
	_makeForm[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern ( Intern const & src )
{
	*this = src;
}

Intern &Intern::operator=( Intern const & rhs )
{
	if (this != &rhs)
	{
		_formNames[0] = rhs._formNames[0];
		_formNames[1] = rhs._formNames[1];
		_formNames[2] = rhs._formNames[2];
		_makeForm[0] = rhs._makeForm[0];
		_makeForm[1] = rhs._makeForm[1];
		_makeForm[2] = rhs._makeForm[2];
	}
	return (*this);
}

Intern::~Intern ( void ) { }

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*_makeForm[i])(target));
		}
	}
	std::cout << "Intern can't create " << formName << " for target " << target << " because form \"" << formName << "\" doesn't exist" << std::endl;
	throw Intern::FormDoesntExistException();
	return (NULL);
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormDoesntExistException::what() const throw()
{
	return ("Intern :: SORRY I CAN'T CREATE THIS FORM BECAUSE IT DOESN'T EXIST .. :( (but i'm a good intern)");
}