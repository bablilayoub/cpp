/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:36:01 by abablil           #+#    #+#             */
/*   Updated: 2024/08/25 11:02:53 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : fixedPoint(obj.fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->fixedPoint = (value << fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->fixedPoint = roundf(value * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->fixedPoint = obj.fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float)fixedPoint / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return fixedPoint >> fractionalBits;
}