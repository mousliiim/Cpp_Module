/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 21:21:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main ( void )
{
		Bureaucrat mouss("Mouss", 10);
		Bureaucrat maxou("Maxou", 30);
		Form formulaire_one("Formulaire_One", 10, 10);
		Form formulaire_two("Formulaire_Two", 29, 29);

		std::cout << mouss << maxou << "\n";
		std::cout << formulaire_one << formulaire_two << "\n";

		maxou.signForm(formulaire_one);
		mouss.signForm(formulaire_two);
		maxou.signForm(formulaire_two);
		mouss.signForm(formulaire_one);
		
		std::cout << "\n" << formulaire_one;
		std::cout << formulaire_two << "\n";
	
	try 
	{
		Form formulaire_three("Formulaire_Three", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form formulaire_four("Formulaire_Four", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "\n";
	}
	return (0);
}