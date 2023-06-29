/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/29 22:18:06 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ( void )
{
	Serializer serialize;
	Data data_one;
	Data *data_two;
	uintptr_t ptr = 0;

	data_one.name = "Mouslim";
	data_one.age = 22;
	std::cout << "Data of data_one : \n";
	std::cout << "Name : " << data_one.name << "\n"; 
	std::cout << "Age : " << data_one.age << "\n\n";
	std::cout << "uintptr_t value before serialize : " << ptr << "\n";
	ptr = serialize.serialize(&data_one);
	std::cout << "uintptr_t value after serialize : " << ptr << "\n";
	std::cout << "Memory adress of data_one : " << &data_one << "\n";
	std::cout << "Memory adress of data_two before deserialize data_one in data_two : " << data_two << "\n";
	data_two = serialize.deserialize(ptr);
	std::cout << "Memory adress of data_two after deserialize data_one in data_two : " << data_two << "\n";

	std::cout << "\n";
	std::cout << "Data of data_two : \n";
	std::cout << "Name : " << data_two->name << "\n"; 
	std::cout << "Age : " << data_two->age << std::endl;
}