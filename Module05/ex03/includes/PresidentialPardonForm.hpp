/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 18:54:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm ( void );
		PresidentialPardonForm ( std::string const &target );
		PresidentialPardonForm ( PresidentialPardonForm const & src );
		~PresidentialPardonForm ( void );
		PresidentialPardonForm &operator=( PresidentialPardonForm const & rhs );
		virtual void execute(Bureaucrat const & executor) const;
		virtual std::string	getTarget ( void ) const;

	private:
		int 		_gradeExec;
		std::string _target;
};
#endif