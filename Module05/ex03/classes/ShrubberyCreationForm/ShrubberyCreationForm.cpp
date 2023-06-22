/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:11:03 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 18:54:21 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
# define BROWN   "\033[1;33m"
# define GREEN   "\033[1;32m"
# define RESET   "\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm ( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("default_shrubbery") { _gradeExec = 137; }

ShrubberyCreationForm::ShrubberyCreationForm ( std::string const &target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shrubbery") { _gradeExec = 137; }

ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const & src ) { *this = src; }

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) { }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	std::ofstream file;
	file.open(this->_target.c_str());
	if (file.is_open())
	{
		file << "\n\n";
		for (int i = 0; i < 3; i++)
		{
			file << GREEN << "		                  # #### ####\n";
			file << "		                ### \\/#|### |/####\n";
			file << "		               ## \\/#/ \\||/##/_/##/_#\n";
			file << "		             ###  \\/###|/ \\/ # ###\n";
			file << "		           ##_\\_\\#\\_\\## | #/###_/_####\n";
			file << "		          ## #### # \\ #| /  #### ##/##\n";
			file << "		           __#_--###`  |{,###---###-~\n" << BROWN;
			file << "		                     \\ }{\n";
			file << "		                      }}{\n";
			file << "		                      }}{\n";
			file << "		                      {{}\n";
			file << "		                  # #### ####" << std::endl << std::endl << std::endl << RESET;
		}
	}
	else 
		std::cerr << "Error: could not open file" << std::endl;
	file.close();
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		this->_gradeExec = rhs._gradeExec;
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget ( void ) const { return (this->_target); }
