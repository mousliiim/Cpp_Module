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
		std::string	getIdeas ( const int index ) const;
		void		setIdeas ( const int index, std::string idea );
	private:
		std::string _ideas[100];
};

#endif