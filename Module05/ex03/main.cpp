/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/21 23:15:33 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main ( void )
{
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 1);
		Bureaucrat b3("b3", 5);
		std::cout << "\n************ TEST IF ALL IS CORRECT (SIGNED AND LEVEL OK) ************\n";
		AForm *form1 = new ShrubberyCreationForm("b1form");
		b1.signForm(*form1);
		b1.executeForm(*form1);
		std::cout << "\n";
		AForm *form2 = new RobotomyRequestForm("b2form");
		b2.signForm(*form2);
		b2.executeForm(*form2);
		std::cout << "\n";
		AForm *form3 = new PresidentialPardonForm("b3form");
		b3.signForm(*form3);
		b3.executeForm(*form3);
		std::cout << "\n\n";
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 1);
		Bureaucrat b3("b3", 5);
		std::cout << "\n************ TEST IF FORM IS NOT SIGNED ************\n";
		AForm *form4 = new ShrubberyCreationForm("bad_b1form");
		b1.executeForm(*form4);
		std::cout << "\n";
		AForm *form5 = new RobotomyRequestForm("bad_b2form");
		b2.executeForm(*form5);
		std::cout << "\n";
		AForm *form6 = new PresidentialPardonForm("bad_b3form");
		b3.executeForm(*form6);
		std::cout << "\n\n";
		delete form4;
		delete form5;
		delete form6;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\n************ TEST IF GRADE IS TOO LOW ************\n";
		Bureaucrat b4("b4", 145);
		AForm *form7 = new ShrubberyCreationForm("bad_b4form");
		b4.signForm(*form7);
		b4.executeForm(*form7);
		std::cout << "\n";
		Bureaucrat b5("b5", 137);
		AForm *form8 = new RobotomyRequestForm("bad_b5form");
		b5.signForm(*form8);
		b5.executeForm(*form8);
		std::cout << "\n";
		Bureaucrat b6("b6", 26);
		AForm *form9 = new PresidentialPardonForm("bad_b6form");
		b6.signForm(*form9);
		b6.executeForm(*form9);
		std::cout << "\n\n";
		delete form7;
		delete form8;
		delete form9;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}