/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:45:57 by abablil           #+#    #+#             */
/*   Updated: 2024/08/27 15:38:57 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float absolute(float n)
{
	if (n < 0)
		return -n;
	return n;
}

float area(Point const &a, Point const &b, Point const &c) {
    float x1 = a.getX();
    float y1 = a.getY();

    float x2 = b.getX();
    float y2 = b.getY();

    float x3 = c.getX();
    float y3 = c.getY();

    float determinant = x1 * (y2 - y3) 
                      + x2 * (y3 - y1) 
                      + x3 * (y1 - y2);
    return absolute(determinant) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float total_area = area(a, b, c);
    float area1 = area(point, a, b);
    float area2 = area(point, b, c);
    float area3 = area(point, c, a);

	if (total_area == 0 || area1 == 0 || area2 == 0 || area3 == 0)
		return false;
    return (total_area == area1 + area2 + area3);
}