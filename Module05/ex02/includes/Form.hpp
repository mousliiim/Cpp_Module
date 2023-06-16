/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:20 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 22:04:25 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	public:
		Form ( void );
		Form ( const std::string &Name, const int &GradeSign, const int &GradeExecute );
		Form ( const Form &src );
		Form &operator= ( const Form &src );
		virtual ~Form ( void ) = 0;
		
		std::string getName ( void ) const;
		bool 		getSigned ( void ) const;
		int			getGradeSign ( void ) const;
		int			getGradeExecute ( void ) const;
		void		beSigned ( const Bureaucrat &bureaucrat );

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

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif