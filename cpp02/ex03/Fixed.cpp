/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:36:01 by abablil           #+#    #+#             */
/*   Updated: 2024/08/27 16:00:11 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {}

Fixed::Fixed(const Fixed &obj) : fixedPoint(obj.fixedPoint) {}

Fixed::Fixed(const int value)
{
	this->fixedPoint = (value << fractionalBits);
}

Fixed::Fixed(const float value)
{
	this->fixedPoint = roundf(value * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->fixedPoint = obj.fixedPoint;
	return *this;
}

bool Fixed::operator>(const Fixed &obj) const
{
	if (this->fixedPoint > obj.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &obj) const
{
	if (this->fixedPoint < obj.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &obj) const
{
	if (this->fixedPoint >= obj.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &obj) const
{
	if (this->fixedPoint <= obj.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &obj) const
{
	if (this->fixedPoint == obj.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &obj) const
{
	if (this->fixedPoint != obj.fixedPoint)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	result.fixedPoint = this->fixedPoint + obj.fixedPoint;
	return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;
	result.fixedPoint = this->fixedPoint - obj.fixedPoint;
	return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	result.fixedPoint = (this->fixedPoint * obj.fixedPoint) >> fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed result;
	result.fixedPoint = (this->fixedPoint << fractionalBits) / obj.fixedPoint;
	return result;
}

Fixed &Fixed::operator++()
{
	this->fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

Fixed::~Fixed() {}

int	Fixed::getRawBits() const
{
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
