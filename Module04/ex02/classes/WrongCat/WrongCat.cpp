#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") { std::cout << "WrongCat :: Default Constructor Called\n"; }

WrongCat::WrongCat ( std::string typeOfAnimal ) : WrongAnimal(typeOfAnimal) { std::cout << "WrongCat :: Constructor Called\n"; }

WrongCat::WrongCat( const WrongCat &src ) : WrongAnimal ( src )
{
	*this = src;
	std::cout << "WrongCat :: Copy Constructor Called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() { std::cout << "WrongCat :: Destructor Called\n"; }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat	&WrongCat::operator=( WrongCat const &rhs )
{
	if ( this != &rhs )
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound ( void ) const
{
	std::cout << "< " << this->getType() << " > : Miiiaaaouuuuu !\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongCat::getType ( void ) const
{
	return (this->type);
}

/* ************************************************************************** */