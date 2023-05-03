/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 02:06:53 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 02:09:42 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

bool IsEmpty(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

bool CheckIfAlpha(std::string input)
{
	bool isOther = false;
	bool isAlpha = false;
	for(int i = 0; input[i]; i++)
	{
		if (std::isalpha(input[i]))
			isAlpha = true;
		if (!std::isalpha(input[i]) && !std::isspace(input[i]))
			isOther = true;
	}
	if (isAlpha && !isOther)
			return (true);
	return (false);
}

bool CheckIfDigit(std::string input)
{
	bool isOther = false;
	bool isDigit = false;
	for(int i = 0; input[i]; i++)
	{
		if (std::isdigit(input[i]))
			isDigit = true;
		if (!std::isdigit(input[i]) && !std::isspace(input[i]))
			isOther = true;
	}
	if (isDigit && !isOther)
			return (true);
	return (false);
}

std::string TakeInfo(std::string info, std::string CharOrDigit)
{
	std::string input;
	static int flag = 0;
	
	if (!flag)
		std::cout << std::endl;
	std::cout << "Enter " << info << ": ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << WHITE << "\n\nGoodbye ! 👋" << RESET << std::endl;
		exit(0);
	}
	if (CharOrDigit == "ALPHA")
	{
		while (IsEmpty(input) || !CheckIfAlpha(input))
		{
			if (IsEmpty(input))
				std::cout << info << " can't be empty" << std::endl;
			else if (!CheckIfAlpha(input))
				std::cout << info << " can only contain alphabetical character" << std::endl;
			std::cout << "Enter " << info << ": ";
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << WHITE << "\n\nGoodbye ! 👋" << RESET << std::endl;
				exit(0);
			}
		}
	}
	else if (CharOrDigit == "DIGIT")
	{
		while (IsEmpty(input) || !CheckIfDigit(input))
		{
			if (IsEmpty(input))
				std::cout << info << " can't be empty" << std::endl;
			else if (!CheckIfDigit(input))
				std::cout << info << " can contain only digit" << std::endl;
			std::cout << "Enter " << info << ": ";
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << WHITE << "\n\nGoodbye ! 👋" << RESET << std::endl;
				exit(0);
			}
		}
	}
	flag++;
	if (flag == 5)
	{
		std::cout << std::endl;
		flag = 0;
	}
	return (input);
}