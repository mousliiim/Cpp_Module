#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal ( void ) : type("Default") { std::cout << "Animal :: Default Constructor Called\n"; }

Animal::Animal ( std::string typeOfAnimal ) : type(typeOfAnimal) { std::cout << "Animal :: Constructor Called\n"; }

Animal::Animal( const Animal &src )
{
	*this = src;
	std::cout << "Animal :: Copy Constructor Called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() { std::cout << "Animal :: Destructor Called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=( Animal const &rhs )
{
	if ( this != &rhs )
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound ( void ) const
{
	std::cout << "< " << this->getType() << " > : ** MAKE SOUND ** !\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType ( void ) const
{
	return (this->type);
}

void Animal::setType ( std::string typeOfAnimal )
{
	this->type = typeOfAnimal;
}

/* ************************************************************************** */