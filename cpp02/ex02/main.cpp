/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:12:15 by abablil           #+#    #+#             */
/*   Updated: 2024/08/31 16:21:52 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	else if (a < b)
		std::cout << "a < b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	std::cout << b + a << std::endl;
	std::cout << b * a << std::endl;
	std::cout << b / a << std::endl;
	return 0;
}
