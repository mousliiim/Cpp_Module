/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/12 20:52:06 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main ( void )
{
	std::cout << "\n*********************************************\n\n";
	std::cout << "First test will not have error because grade is 150 for default constructor\n\n";
	try 
	{
		Bureaucrat test_one;
		std::cout << test_one;
	}
	catch ( std::exception &error ) 
	{
		std::cerr << "Enter in catch because : \n";
		std::cerr << error.what() << "\n";
	}
	std::cout << "\n*********************************************\n\n";

	std::cout << "First test will be have error because grade is too high (151)\n";
	std::cout << "Second test will be have error because grade is too low (0)\n";
	try 
	{
		Bureaucrat test_two("test_two", 151);
		std::cout << test_two;	
	}
	catch ( std::exception &error ) 
	{
		std::cerr << "\nEnter in catch because : \n";
		std::cerr << error.what() << "\n\n";
	}

	try 
	{
		Bureaucrat test_three("test_three", 0);
		std::cout << test_three;	
	}
	catch ( std::exception &error ) 
	{
		std::cerr << "\nEnter in catch because : \n";
		std::cerr << error.what() << "\n\n";
	}

	std::cout << "*********************************************\n\n";
	std::cout << "First test will not have error because grade is 150 after upGrade is 149\n";
	std::cout << "Second test will be have error because grade is 150 after downGrade is 151\n\n";
	try 
	{
		Bureaucrat test_four("test_four", 150);
		std::cout << test_four;
		test_four.upGrade();
		std::cout << test_four;
	}
	catch ( std::exception &error ) 
	{
		std::cerr << "\nEnter in catch because : \n";
		std::cerr << error.what() << "\n";
	}

	try 
	{
		Bureaucrat test_five("test_five", 150);
		std::cout << "\n" << test_five;
		test_five.downGrade();
		std::cout << test_five;
	}
	catch ( std::exception &error ) 
	{
		std::cerr << "\nEnter in catch because : \n";
		std::cerr << error.what() << "\n\n";
	}
}