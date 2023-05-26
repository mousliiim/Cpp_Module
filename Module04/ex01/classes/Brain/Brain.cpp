#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain( void ) { std::cout << "Brain :: Default constructor called" << std::endl; }

Brain::Brain( const Brain & src )
{
	std::cout << "Brain :: Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() { std::cout << "Brain :: Destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=( Brain const & rhs )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs.getIdeas(i);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Brain::getIdeas( const int index ) const
{
	return this->_ideas[index];
}

void Brain::setIdeas( const int index, std::string &idea )
{
	this->_ideas[index] = idea;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */