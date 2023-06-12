/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:44:20 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/12 20:58:51 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat 
{
	public:
		Bureaucrat ();
		Bureaucrat ( const std::string &Name, const int &_Grade);
		Bureaucrat ( Bureaucrat const &src );
		Bureaucrat &operator= ( Bureaucrat const &rhs );
		~Bureaucrat ();

		std::string getName ( void ) const;
		int			getGrade( void ) const;
		void		upGrade ( void );
		void		downGrade ( void );
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return ("Grade too high"); }
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return ("Grade too low"); }
	};
	
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif
