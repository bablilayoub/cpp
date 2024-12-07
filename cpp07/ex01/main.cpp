/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:27:22 by abablil           #+#    #+#             */
/*   Updated: 2024/12/07 22:38:09 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void toUpper(std::string &str)
{
	for (std::size_t i = 0; i < str.length(); i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (char)toupper(str[i]);
}

void plusFive(int &i)
{
	i = i + 5;
}

int main(void)
{
	std::string array[] = {"First", "Second", "Third"};
	iter(array, 3, toUpper);

	for (std::size_t i = 0; i < 3; i++)
		std::cout << array[i] << std::endl;

	int numbers[] = {5, 15, 25};
	iter(numbers, 3, plusFive);

	for (std::size_t i = 0; i < 3; i++)
		std::cout << numbers[i] << std::endl;

	return 0;
}
