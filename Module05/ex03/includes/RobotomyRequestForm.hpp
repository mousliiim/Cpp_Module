/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:46 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/21 23:17:45 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm ( void );
		RobotomyRequestForm ( std::string const &target );
		RobotomyRequestForm ( RobotomyRequestForm const & src );
		~RobotomyRequestForm ( void );
		RobotomyRequestForm &operator=( RobotomyRequestForm const & rhs );
		virtual void execute(Bureaucrat const & executor) const;

	private:
		int 		_gradeExec;
		std::string _target;
};

#endif