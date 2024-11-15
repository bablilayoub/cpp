/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:34:46 by abablil           #+#    #+#             */
/*   Updated: 2024/11/11 14:42:19 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog dog;
	Dog dog1 = dog;

	Cat cat;
	Cat cat1(cat);

	Animal *animal[100];

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
		delete animal[i];
	return 0;
}