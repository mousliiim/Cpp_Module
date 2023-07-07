/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/07 23:17:50 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	public:
		Array(void) : _size(0), _array(new T[_size]) {}

		Array(unsigned int n) : _size(n), _array(new T[_size])
		{
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = T();
		}
		Array(Array const & src) : _size(src._size), _array(new T[_size])
		{
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}
		
		~Array(void) { delete [] this->_array; }

		T &operator[](unsigned int n)
		{
			if (n >= this->_size || n < 0)
				throw OutOfLimitsException();
			return this->_array[n];
		}

		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_size = rhs._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = rhs._array[i];
			}
			return *this;
		}

		unsigned int size(void) const { return this->_size; }
		
		T getValue (unsigned int n) const
		{
			if (n >= this->_size || n < 0)
				throw OutOfLimitsException();
			return this->_array[n];
		
		}
		void setValue (unsigned int n, T value)
		{
			if (n >= this->_size || n < 0)
				throw OutOfLimitsException();
			this->_array[n] = value;
		
		}
		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Array :: Out of limits");
				}
		};

	private:
		unsigned int _size;
		T *_array;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr)
{
    for (unsigned int i = 0; i < arr.size(); ++i)
      os << arr.getValue(i) << " | ";
    return os;
}

#endif