/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:10:43 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 19:02:23 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm ( void ) : AForm("RobotomyRequestForm", 72, 45), _target("default_robotomy") { _gradeExec = 45; }

RobotomyRequestForm::RobotomyRequestForm ( std::string const &target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) { _gradeExec = 45; }

RobotomyRequestForm::RobotomyRequestForm ( RobotomyRequestForm const & src ) { *this = src; }

RobotomyRequestForm::~RobotomyRequestForm ( void ) { }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	std::cout << "Bzzz Bzzzzzzzzzzzzzzzzzzz BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n";
	srand(time(0));
	(rand() % 2 == 0) ? std::cout << this->_target << " has been robotomized successfully\n" : std::cout << this->_target << " robotomization failed\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->_gradeExec = rhs._gradeExec;
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget ( void ) const { return (this->_target); }
