#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal ( void ) : type("Default") { std::cout << "WrongAnimal :: Default Constructor Called\n"; }

WrongAnimal::WrongAnimal ( std::string typeOfAnimal ) : type(typeOfAnimal) { std::cout << "WrongAnimal :: Constructor Called\n"; }

WrongAnimal::WrongAnimal( const WrongAnimal &src )
{
	*this = src;
	std::cout << "WrongAnimal :: Copy Constructor Called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal :: Destructor Called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
		*this = rhs;
	return *this;
}

std::ostream &operator<<( std::ostream &o, WrongAnimal const &rhs )
{
	o << "Value = " << rhs.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound ( void ) const
{
	std::cout << "< " << this->getType() << " > : ** MAKE SOUND ** !\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType ( void ) const
{
	return (this->type);
}

void WrongAnimal::setType ( std::string &typeOfAnimal )
{
	this->type = typeOfAnimal;
}

/* ************************************************************************** */