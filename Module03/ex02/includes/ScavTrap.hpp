#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap ( void );
		ScavTrap ( ScavTrap const &src );
		ScavTrap ( const std::string &name );
		~ScavTrap ( void );
		ScavTrap &operator= ( ScavTrap const & rhs );

		void	guardGate	( void );
		void	attack		( const std::string &target );
};

#endif