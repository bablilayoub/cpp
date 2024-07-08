/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:50:15 by abablil           #+#    #+#             */
/*   Updated: 2024/07/08 11:38:14 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl test = Harl();
	test.complain("DEBUG");
	test.complain("ERROR");
	test.complain("WARNING");
	test.complain("INFO");
	return (0);
}