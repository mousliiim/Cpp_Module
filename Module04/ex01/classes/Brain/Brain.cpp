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
	std::string ideas;
	for (int i = 0; i < 100; i++)
	{
		ideas = rhs.getIdeas(i);
		if (ideas.empty())
			continue;
		else
			this->setIdeas(i, ideas);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Brain::getIdeas( const int index ) const
{
	return this->_ideas[index];
}

void Brain::setIdeas( const int index, std::string idea )
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << "Error: index out of range of array limit\n";
}

/* ************************************************************************** */