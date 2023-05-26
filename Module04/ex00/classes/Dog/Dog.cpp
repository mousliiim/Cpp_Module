#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog ( void ) : Animal("Dog") { std::cout << "Dog :: Default Constructor Called\n"; }

Dog::Dog ( std::string typeOfAnimal ) : Animal(typeOfAnimal) { std::cout << "Dog :: Constructor Called\n"; }

Dog::Dog ( const Dog &src ) : Animal ( src )
{
	*this = src;
	std::cout << "Dog :: Copy Constructor Called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog ( void ) { std::cout << "Dog :: Destructor Called\n";}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog	&Dog::operator= ( Dog const &rhs )
{
	if ( this != &rhs )
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Dog::makeSound ( void ) const
{
	std::cout << "< " << this->getType() << " > : Ouaf Ouaf Ouaf !\n";
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Dog::getType ( void ) const
{
	return (this->type);
}

/* ************************************************************************** */