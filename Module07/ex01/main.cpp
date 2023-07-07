/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/07 21:51:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::cout << "\n I CALL THE ITER FUNCTION WITH FUNCTION PRINT AS PARAMETER" << std::endl;
	std::cout << "\n********** INT TAB ITER ****************" << std::endl;
	int tab_int[] = {0, 1, 2, 3, 4, 5};
	iter(tab_int, 6, print);
	std::cout << "****************************************" << std::endl;
	std::cout << "\n********** STRING TAB ITER *************" << std::endl;
	std::string tab_string[] = {"salut", "les", "amis", "comment", "ca", "va", "?"};
	iter(tab_string, 7, print);
	std::cout << "****************************************" << std::endl;
	std::cout << "\n********** FLOAT TAB ITER **************" << std::endl;
	float tab_float[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	iter(tab_float, 6, print);
	std::cout << "****************************************" << std::endl;
	return 0;
}