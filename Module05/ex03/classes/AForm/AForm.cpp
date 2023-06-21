/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:35:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/21 23:27:11 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm ( void ) { }

AForm::AForm ( void ) : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {} 

AForm::AForm ( const std::string &Name, const int &GradeSign, const int &GradeExecute ) : _name(Name), _isSigned(false), _gradeSign(GradeSign), _gradeExecute(GradeExecute)
{
	if (GradeSign <= 0 || GradeExecute <= 0)
		throw AForm::GradeTooHighException();
	else if ( GradeSign > 150 || GradeExecute > 150 )
		throw AForm::GradeTooLowException();
}

AForm::AForm ( AForm const & src ) : _name(src.getName()), _isSigned(src.getSigned()), _gradeSign(src.getGradeSign()), _gradeExecute(src.getGradeExecute())
{
	if (src.getGradeSign() <= 0 || src.getGradeExecute() <= 0)
		throw AForm::GradeTooHighException();
	else if ( src.getGradeSign() > 150 || src.getGradeExecute() > 150 )
		throw AForm::GradeTooLowException();
}

AForm &AForm::operator=( AForm const & src )
{
	if (this == &src)
		return (*this);
	this->_isSigned = src.getSigned();
	return (*this);
}

int AForm::getGradeSign ( void ) const { return (_gradeSign); }

int AForm::getGradeExecute ( void ) const { return (_gradeExecute); }

std::string AForm::getName ( void ) const { return (_name); }

bool AForm::getSigned ( void ) const { return (_isSigned); }

void AForm::beSigned ( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form :: Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form :: Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form :: Form not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and require minimum grade " << form.getGradeSign() << " to be signed and grade " << form.getGradeExecute() << " to be executed\n";
	return (out);
}