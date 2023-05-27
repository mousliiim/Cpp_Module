#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain( void ) { std::cout << "Brain :: Default constructor called\n"; }

Brain::Brain( const Brain &src )
{
	*this = src;
	std::cout << "Brain :: Copy constructor called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() { std::cout << "Brain :: Destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=( Brain const &rhs )
{
	if ( this != &rhs )
		this->setIdeas(rhs.getIdeas());
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string *Brain::getIdeas( void ) const
{
	return (std::string *)this->_ideas;
}

void Brain::setIdeas( std::string *idea )
{
	for (int i = 0; i < 100; i++)
	{
		if (idea[i].empty())
			break;
		else
			this->_ideas[i] = idea[i];
	}
}

void Brain::printIdeas( void ) const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_ideas[i].empty())
			break;
		else
			std::cout << "Idea " << i + 1 << " : " << this->_ideas[i] << "\n";
	}
}

/* ************************************************************************** */