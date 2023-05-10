/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:59:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/10 22:09:32 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

void	replace( std::string &line, std::string &s1, std::string &s2, bool &find)
{
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.size());
		line.insert(pos, s2);
		pos += s2.size();
		find = true;
	}
}

void exec_replace( std::string fileName, const char *s1_av, const char *s2_av )
{
	std::ifstream file(fileName.c_str());
	std::ofstream outfile;
	std::string line;
	bool find = false;

	fileName += ".replace";
	outfile.open(fileName.c_str(), std::ios::out);
	std::string s1 = s1_av;
	std::string s2 = s2_av;
	while (getline(file, line))
	{
		replace(line, s1, s2, find);
		outfile << line << std::endl;
	}
	if (!find)
	{
		std::cerr << std::endl << RED << "            Error : String to replace not found in file" << RESET << std::endl;
		std::cerr << RED << " File " << fileName << " created but it's just a copy of your original file" << RESET << std::endl << std::endl;
		outfile.close();
	}
	else
	{
		std::cout << std::endl << GREEN << "       All the \"" << s1 << "\" replaced by \"" << s2 << "\" !" << RESET;
		std::cout << std::endl << GREEN << "           File " << fileName << " created" << RESET << std::endl << std::endl;
		outfile.close();
	}
}

void set_error ( int error )
{
	if (error == FILE_ERROR)
		std::cerr << std::endl << RED << "   Error : File not exist or you don't have permission to access this file" << RESET << std::endl << std::endl;
	else if (error == STRING_ERROR)
		std::cerr << RED << std::endl << "       Error : String or character replace or to replace can't be empty" << RESET << std::endl << std::endl;
	exit(1);
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

int main( int argc, char **argv )
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
