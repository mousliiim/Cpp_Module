#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat ( void );
		Cat ( std::string &typeOfAnimal );
		Cat ( Cat const & src );
		~Cat ( void );

		Cat 			&operator= ( Cat const &rhs );
		std::string		getType ( void ) const;	
		Brain 			*getBrain ( void ) const;
		void			makeSound ( void ) const;
	private:
		Brain *_brain;
};

#endif