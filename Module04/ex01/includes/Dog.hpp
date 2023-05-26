#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog ( void );
		Dog ( std::string &typeOfAnimal );
		Dog ( Dog const &src );
		~Dog ( void );

		Dog				&operator= ( Dog const &rhs );
		std::string		getType ( void ) const;
		Brain 			*getBrain ( void ) const;
		void			makeSound ( void ) const;
	private:
		Brain *_brain;
};

#endif