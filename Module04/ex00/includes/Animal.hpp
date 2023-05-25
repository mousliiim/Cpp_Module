#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:
		Animal ( void );
		Animal ( std::string typeOfAnimal );
		Animal ( Animal const & src );
		virtual ~Animal ( void );

		Animal 				&operator= ( Animal const & rhs );
		virtual std::string getType ( void ) const;
		virtual void		setType ( std::string &typeOfAnimal );
		virtual void		makeSound ( void ) const;
	
	protected:
		std::string type;

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif