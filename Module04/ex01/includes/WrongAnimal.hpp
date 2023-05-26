#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal ( void );
		WrongAnimal ( std::string typeOfAnimal );
		WrongAnimal ( WrongAnimal const &src );
		~WrongAnimal ( void );

		WrongAnimal	&operator= ( WrongAnimal const & rhs );
		std::string	getType ( void ) const;
		void		setType ( std::string &typeOfAnimal );
		void		makeSound ( void ) const;
	protected:
		std::string type;
};

#endif