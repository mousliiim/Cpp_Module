#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	std::cout << "FragTrap :: Default Constructor Called" << std::endl;
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name)
{
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	std::cout << "FragTrap :: Constructor Called" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	*this = src;
	std::cout << "FragTrap :: Copy Constructor Called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap :: Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		std::cout << "FragTrap :: Assignement constructor Called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	FragTrap::attack ( const std::string &target )
{
	if (this->ifPossible())
	{
		std::cout << "FragTrap : " << this->_name << " attacks " << target << ", " "causing " << this->getAttackDamage()  << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}


void FragTrap::highFivesGuys ( void )
{
	std::cout << "FragTrap : " << this->_name << " please high fives me ! 👋" << std::endl;
}

/* ************************************************************************** */