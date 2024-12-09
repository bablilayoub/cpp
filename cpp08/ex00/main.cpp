/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:30:32 by abablil           #+#    #+#             */
/*   Updated: 2024/12/09 18:18:01 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::vector<int>::iterator itVec = easyfind(vec, 3);
		std::cout << "Found value in vector: " << *itVec << std::endl;

		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);
		deq.push_back(400);
		deq.push_back(500);
		std::deque<int>::iterator itDeq = easyfind(deq, 400);
		std::cout << "Found value in deque: " << *itDeq << std::endl;

		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);
		std::list<int>::iterator itLst = easyfind(lst, 1000);
		std::cout << "Found value in list: " << *itLst << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}