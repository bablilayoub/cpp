/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:12:15 by abablil           #+#    #+#             */
/*   Updated: 2024/08/27 16:01:52 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(1.0f, 1.0f);
    Point b(5.0f, 1.0f);
    Point c(3.0f, 4.0f);

    Point point(3.0f, 2.0f);
    Point point2(2.0f, 5.0f);
    
    bool inside = bsp(a, b, c, point);
    bool inside2 = bsp(a, b, c, point2);

    std::cout << "Point is ";
    if (!inside) {
        std::cout << "not ";
    }
    std::cout << "inside the triangle." << std::endl;
    std::cout << "Point is ";
    if (!inside2) {
        std::cout << "not ";
    }
    std::cout << "inside the triangle." << std::endl;
    return 0;
}
