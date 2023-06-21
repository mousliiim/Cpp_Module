/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:20 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/21 23:20:18 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include <exception>
# include <fstream>

class Bureaucrat;

class AForm
{
	public:
		AForm ( void );
		AForm ( const std::string &Name, const int &GradeSign, const int &GradeExecute );
		AForm ( const AForm &src );
		AForm &operator= ( const AForm &src );
		virtual ~AForm ( void );
		
		std::string 	getName ( void ) const;
		bool 			getSigned ( void ) const;
		int				getGradeSign ( void ) const;
		int				getGradeExecute ( void ) const;
		void			beSigned ( const Bureaucrat &bureaucrat );
		virtual void	execute ( Bureaucrat const & executor ) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif