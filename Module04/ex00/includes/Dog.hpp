#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog ( void );
		Dog ( std::string typeOfAnimal );
		Dog ( Dog const &src );
		virtual ~Dog ( void );
		Dog	&operator= ( Dog const &rhs );
		
		virtual std::string	getType ( void ) const;
		virtual void		makeSound ( void ) const;
};

#endif