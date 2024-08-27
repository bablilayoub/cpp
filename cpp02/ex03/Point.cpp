/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:20:49 by abablil           #+#    #+#             */
/*   Updated: 2024/08/26 20:04:19 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

float Point::getX() const { return x.toFloat(); }

float Point::getY() const { return y.toFloat(); }

Point &Point::operator=(const Point &obj)
{
	(void)obj;
	return *this;
}
