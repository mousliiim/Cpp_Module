/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:46:05 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 18:54:13 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm ( void );
		ShrubberyCreationForm ( std::string const &target );
		ShrubberyCreationForm ( ShrubberyCreationForm const &src );
		~ShrubberyCreationForm ( void );
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );
		virtual void execute(Bureaucrat const & executor) const;
		virtual std::string	getTarget ( void ) const;
	
	private:
		int 		_gradeExec;
		std::string _target;
};

#endif
