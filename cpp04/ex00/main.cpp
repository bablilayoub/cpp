/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:34:46 by abablil           #+#    #+#             */
/*   Updated: 2024/11/09 17:29:38 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "Animal type: " << j->getType() << " " << std::endl;
	std::cout << "Animal type: " << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* n = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	
	std::cout << "WrongAnimal type: " << c->getType() << " " << std::endl;
	std::cout << "WrongAnimal type: " << n->getType() << " " << std::endl;
	
	n->makeSound();
	c->makeSound();
	
	delete meta;
	delete j;
	delete i;
	delete c;
	delete n;
	return 0;
}