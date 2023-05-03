/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:11:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 02:10:10 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP


#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

std::string	TakeInfo(std::string info, std::string CharOrDigit);
bool		CheckIfAlpha(std::string input);
bool		CheckIfDigit(std::string input);
bool		IsEmpty(std::string);
void		PrintProgramStart(void);

#endif