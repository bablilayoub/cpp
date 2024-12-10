/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:30:32 by abablil           #+#    #+#             */
/*   Updated: 2024/12/10 16:42:42 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	// Valid test
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "-----------------------" << std::endl;

	// Full span
	try
	{
		Span sp = Span(2);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------" << std::endl;

	// Not enough numbers
	try
	{
		Span sp = Span(2);

		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------" << std::endl;

	// addRange test
	try
	{
		Span sp = Span(10000);
		std::vector<int> values;
		values.push_back(10);
		values.push_back(500);
		values.push_back(20);
		values.push_back(5);
		values.push_back(30);
		values.push_back(1);

		sp.addRange(values.begin(), values.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}