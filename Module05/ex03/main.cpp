/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 19:16:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main ( void )
{
	try
	{
		std::cout << "Test if Intern make a Form doesn't exist :" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("FAKE_FORM", "Bender");
		Bureaucrat bender("Bender", 1);
		bender.signForm(*rrf);
		bender.executeForm(*rrf);

		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "----------------------------------------" << std::endl << std::endl << std::endl;
	}

	try
	{
		std::cout << "Test if Intern make a correct Form :" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		std::cout << "Target for this form : " << rrf->getTarget() << std::endl;
		Bureaucrat bender("Bender", 1);
		bender.signForm(*rrf);
		bender.executeForm(*rrf);
		std::cout << "----------------------------------------" << std::endl;

		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}