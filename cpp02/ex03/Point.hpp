/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:20:49 by abablil           #+#    #+#             */
/*   Updated: 2024/08/27 16:01:16 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	float getX() const;
	float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);