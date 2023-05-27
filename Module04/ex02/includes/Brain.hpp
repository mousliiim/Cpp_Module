#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain ( void );
		Brain ( Brain const &src );
		~Brain ( void );

		Brain		&operator=( Brain const &rhs );
		std::string	*getIdeas ( void ) const;
		void		setIdeas ( std::string *idea );
		void 		printIdeas ( void ) const;
	private:
		std::string _ideas[100];
};

#endif