#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap ( void );
		DiamondTrap ( DiamondTrap const &src );
		DiamondTrap ( const std::string &name );
		~DiamondTrap ( void );
		DiamondTrap &operator= ( DiamondTrap const & rhs );

		void 		whoAmI ( void );
		void		attack ( const std::string &target );
		std::string	getNameDt ( void );
	private:
		std::string _name;
};

#endif

