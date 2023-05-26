#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat( void ) : Animal("Cat") { std::cout << "Cat :: Default Constructor Called\n"; }

Cat::Cat ( std::string typeOfAnimal ) : Animal(typeOfAnimal) { std::cout << "Cat :: Constructor Called\n"; }

Cat::Cat( const Cat &src ) : Animal ( src )
{
	*this = src;
	std::cout << "Cat :: Copy Constructor Called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() { std::cout << "Cat :: Destructor Called\n"; }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat	&Cat::operator=( Cat const &rhs )
{
	if ( this != &rhs )
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Cat::makeSound ( void ) const
{
	std::cout << "< " << this->getType() << " > : Miiiaaaouuuuu !\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Cat::getType ( void ) const
{
	return (this->type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */