/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:08:56 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 19:02:14 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) : AForm("PresidentialPardonForm", 25, 5), _target("default_presidential") { _gradeExec = 5; }

PresidentialPardonForm::PresidentialPardonForm ( std::string const &target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) { _gradeExec = 5; }

PresidentialPardonForm::PresidentialPardonForm ( PresidentialPardonForm const & src ) { *this = src; }

PresidentialPardonForm::~PresidentialPardonForm ( void ) { }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->_gradeExec = rhs._gradeExec;
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget ( void ) const { return (this->_target); }