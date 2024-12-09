/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:30:32 by abablil           #+#    #+#             */
/*   Updated: 2024/12/09 21:38:31 by abablil          ###   ########.fr       */
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

	// Full test

	return 0;
}