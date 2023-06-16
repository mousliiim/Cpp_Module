/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:35:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 22:02:48 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form ( void ) { std::cout << "Form :: Destructor called\n"; }

Form::Form ( void ) : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {} 

Form::Form ( const std::string &Name, const int &GradeSign, const int &GradeExecute ) : _name(Name), _isSigned(false), _gradeSign(GradeSign), _gradeExecute(GradeExecute)
{
	if (GradeSign <= 0 || GradeExecute <= 0)
		throw Form::GradeTooHighException();
	else if ( GradeSign > 150 || GradeExecute > 150 )
		throw Form::GradeTooLowException();
}

Form::Form ( Form const & src ) : _name(src.getName()), _isSigned(src.getSigned()), _gradeSign(src.getGradeSign()), _gradeExecute(src.getGradeExecute())
{
	if (src.getGradeSign() <= 0 || src.getGradeExecute() <= 0)
		throw Form::GradeTooHighException();
	else if ( src.getGradeSign() > 150 || src.getGradeExecute() > 150 )
		throw Form::GradeTooLowException();
}

Form &Form::operator=( Form const & src )
{
	if (this == &src)
		return (*this);
	this->_isSigned = src.getSigned();
	return (*this);
}
int Form::getGradeSign ( void ) const { return (_gradeSign); }

int Form::getGradeExecute ( void ) const { return (_gradeExecute); }

std::string Form::getName ( void ) const { return (_name); }

bool Form::getSigned ( void ) const { return (_isSigned); }

void Form::beSigned ( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form :: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form :: Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and require minimum grade " << form.getGradeSign() << " to be signed and grade " << form.getGradeExecute() << " to be executed\n";
	return (out);
}