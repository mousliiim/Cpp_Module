/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 22:06:06 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat ( const std::string &Name, const int &Grade ) : _name(Name)
{
	if (Grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if ( Grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	_grade = Grade;
}

Bureaucrat::Bureaucrat ( Bureaucrat const & src ) { *this = src; }

Bureaucrat &Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat () { std::cout << "Bureaucrat :: Destructor called\n"; }

std::string Bureaucrat::getName ( void ) const { return (_name); }

int	Bureaucrat::getGrade( void ) const { return (_grade); }

void Bureaucrat::upGrade ( void )
{
	if ((_grade - 1) <= 0)
	{
		std::cerr << "Bureaucrat :: upGrade error\n";
		throw Bureaucrat::GradeTooLowException();
	}
	_grade--;
}

void	Bureaucrat::downGrade ( void )
{
	if ((_grade + 1) > 150)
	{
		std::cerr << "Bureaucrat :: downGrade error\n";
		throw Bureaucrat::GradeTooHighException();
	}
	_grade++;
}

void	Bureaucrat::signForm ( Form &form ) 
{
	if (_grade > form.getGradeSign())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because his grade is too low";
		form.getSigned() == true ? std::cout << " and the form is already signed\n" : std::cout << "\n";
	}
	else if (form.getSigned())
		std::cout << _name << " couldn't sign " << form.getName() << " because the form is already signed\n";
	else
	{
		std::cout << _name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat :: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat :: Grade too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return (out);
}
