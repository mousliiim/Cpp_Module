#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat ( void );
		Cat ( std::string typeOfAnimal );
		Cat ( Cat const & src );
		virtual ~Cat ( void );
		Cat &operator= ( Cat const &rhs );
		
		virtual std::string	getType ( void ) const;
		virtual void		makeSound ( void ) const;
};

#endif