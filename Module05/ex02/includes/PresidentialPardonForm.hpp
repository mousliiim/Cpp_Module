/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/16 22:08:14 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <exception>

# include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm ( void );
		PresidentialPardonForm ( PresidentialPardonForm const & src );
		~PresidentialPardonForm ( void );
		PresidentialPardonForm &operator=( PresidentialPardonForm const & rhs );
};
#endif