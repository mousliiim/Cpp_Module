/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:59:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/10 03:13:24 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

void	replace(std::string& line)
{
	// FIND POUR TROUVER LE MOT
	//  ERASE POUR EFFACER LE MOT TROUVER
	// INSERT
	// UTILISER LE LENGHT POUR ECRIRE
	// while ()
	// {
		/* code */
	// }
}

void exec_replace(std::string &fileName, const char *s1_av, const char *s2_av)
{
	std::ifstream file(fileName.c_str());
	std::ofstream outfile;
	std::string line;

	fileName += ".replace";
	outfile.open(fileName.c_str(), std::ios::out);
	std::string s1 = s1_av;
	std::string s2 = s2_av;
	while (getline(file, line))
	{
		outfile << line << std::endl;
	}	
}

void set_error ( int error )
{
	if (error == FILE_ERROR)
		std::cerr << std::endl << RED << "   Error : File not exist or you don't have permission to access this file" << RESET << std::endl << std::endl;
	else if (error == STRING_ERROR)
		std::cerr << RED << std::endl << "       Error : String or character replace or to replace can't be empty" << RESET << std::endl << std::endl;
	exit(0);
}

bool checkFile ( const char &fileName )
{
	bool verif = false;
	struct stat fileInfo;
	
	if (stat(&fileName, &fileInfo) == 0)
	{
		if (S_ISDIR(fileInfo.st_mode))
			verif = false;
		else
			verif = true;
	}
	return (verif);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << std::endl << RED << "       Wrong number of arguments you have " << (argc - 1) << " parameter(s) need 3" << RESET << std::endl;
		std::cerr << WHITE << "Usage: ./replace [filename] [string to replace] [string to replace with]" << RESET << std::endl << std::endl;
		return (0);
	}
	else
	{
		if (!checkFile(*argv[1]))
			set_error(FILE_ERROR);
		if (!argv[2][0] || !argv[3][0])
			set_error(STRING_ERROR);
		exec_replace(argv[1], argv[2], argv[3]);
	}
	return 0;
}
