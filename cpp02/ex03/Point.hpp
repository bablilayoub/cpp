/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:20:49 by abablil           #+#    #+#             */
/*   Updated: 2024/07/31 09:48:07 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Point {
private:
	const float x;
	const float y;
public:
	Point();
	Point(float x, float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	float getX() const;
	float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);