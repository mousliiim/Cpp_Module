/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousspc <mousspc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:31:58 by mousspc           #+#    #+#             */
/*   Updated: 2023/05/06 01:06:04 by mousspc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptrStr = &str;
    std::string &refStr = str;

    int num = 42;
    int *ptrNum = &num;
    int &refNum = num;

    std::cout << std::endl << "-----------------------------------" << std::endl;
    std::cout << "Adress of str is : " << &str << std::endl;
    std::cout << "Adress of ptrStr is : " << ptrStr << std::endl;
    std::cout << "Adress of refStr is : " << &refStr << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Value of str is : " << str << std::endl;
    std::cout << "Value of ptrStr is : " << *ptrStr << std::endl;
    std::cout << "Value of refStr is : " << refStr << std::endl;
    std::cout << "-----------------------------------" << std::endl << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Adress of num is : " << &num << std::endl;
    std::cout << "Adress of ptrNum is : " << ptrNum << std::endl;
    std::cout << "Adress of refNum is : " << &refNum << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Value of num is : " << num << std::endl;
    std::cout << "Value of ptrNum is : " << *ptrNum << std::endl;
    std::cout << "Value of refNum is : " << refNum << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Increment num by 1 and watch the changes :" << std::endl;
    num++;
    std::cout << "Value of num is : " << num << std::endl;
    std::cout << "Value of ptrNum is : " << *ptrNum << std::endl;
    std::cout << "Value of refNum is : " << refNum << std::endl;
    std::cout << "-----------------------------------" << std::endl << std::endl;
}