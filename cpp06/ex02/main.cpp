/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:43:15 by abablil           #+#    #+#             */
/*   Updated: 2024/12/01 12:56:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    Base* obj = generate();
    std::cout << "Identify using pointer: ";
    identify(obj);

    std::cout << "Identify using reference: ";
    identify(*obj);

    delete obj;
    return 0;
}
