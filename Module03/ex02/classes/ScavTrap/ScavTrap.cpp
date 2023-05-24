#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	std::cout << "ScavTrap :: Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name)
{
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	std::cout << "ScavTrap :: Constructor Called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	*this = src;
	std::cout << "ScavTrap :: Copy Constructor Called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap :: Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=( ScavTrap const &rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		std::cout << "ScavTrap :: Assignement constructor Called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::attack ( const std::string &target )
{
	if (this->ifPossible())
	{
		std::cout << "ScavTrap : " << this->_name << " attacks " << target << ", " "causing " << this->getAttackDamage()  << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}


void ScavTrap::guardGate ( void )
{
	std::cout << "ScavTrap : " << this->_name << " enter in Gate keeper mode" << std::endl;
}

/* ************************************************************************** */