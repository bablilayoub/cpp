/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:27:22 by abablil           #+#    #+#             */
/*   Updated: 2024/12/07 23:11:45 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	// Test default constructor
	Array<int> arr1;
	std::cout << "arr1 size: " << arr1.size() << std::endl;

	// Test constructor with size
	Array<int> arr2(5);
	std::cout << "arr2 size: " << arr2.size() << std::endl;
	for (unsigned int i = 0; i < arr2.size(); ++i)
		arr2[i] = i * 2;
	for (unsigned int i = 0; i < arr2.size(); ++i)
		std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;

	// Test copy constructor
	Array<int> arr3(arr2);
	std::cout << "arr3 size: " << arr3.size() << std::endl;
	for (unsigned int i = 0; i < arr3.size(); ++i)
		std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;

	// Test assignment operator
	Array<int> arr4;
	arr4 = arr2;
	std::cout << "arr4 size: " << arr4.size() << std::endl;
	for (unsigned int i = 0; i < arr4.size(); ++i)
		std::cout << "arr4[" << i << "] = " << arr4[i] << std::endl;

	// Test out of bounds access
	try
	{
		std::cout << "arr2[10] = " << arr2[10] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
