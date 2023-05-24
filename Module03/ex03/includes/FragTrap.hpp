#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap ( void );
		FragTrap ( FragTrap const &src );
		FragTrap ( const std::string &name );
		~FragTrap ( void );
		FragTrap &operator= ( FragTrap const & rhs );

		void highFivesGuys ( void );
		void	attack ( const std::string &target );
};

#endif