/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:30:32 by abablil           #+#    #+#             */
/*   Updated: 2024/12/10 21:43:01 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<std::string> stack;
	stack.push("Hello");
	stack.push("how are");
	stack.push("you");
	stack.push("!!!!");

	if (stack.empty())
	{
		std::cout << "stack is empty" << std::endl;
		return 0;
	}

	std::cout << "Size : " << stack.size() << std::endl;
	stack.pop();
	std::cout << "Size : " << stack.size() << std::endl;

	MutantStack<std::string>::iterator begin = stack.begin();
	MutantStack<std::string>::iterator end = stack.end();

	std::cout << "Top element : " << stack.top() << std::endl;

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
	return 0;
}

// int main()
// {
// 	MutantStack<int> stack;
// 	stack.push(1337);
// 	stack.push(42);
// 	stack.push(2024);
// 	stack.push(0);

// 	if (stack.empty())
// 	{
// 		std::cout << "stack is empty" << std::endl;
// 		return 0;
// 	}
	
// 	std::cout << "Size : " << stack.size() << std::endl;
// 	stack.pop();
// 	std::cout << "Size : " << stack.size() << std::endl;

// 	MutantStack<int>::iterator begin = stack.begin();
// 	MutantStack<int>::iterator end = stack.end();

// 	std::cout << "Top element : " << stack.top() << std::endl;

// 	while (begin != end)
// 	{
// 		std::cout << *begin << std::endl;
// 		++begin;
// 	}
// 	return 0;
// }