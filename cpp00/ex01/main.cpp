/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:37:38 by abablil           #+#    #+#             */
/*   Updated: 2024/07/04 12:12:44 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phone_book;
	std::string command;
	int			current_i;

	current_i = 0;
	phone_book.total_contacts = 0;
	std::cout << "Enter a command : (ADD, SEARCH, EXIT)" << std::endl;
	while (std::getline(std::cin, command))
	{
		if (command.empty())
		{
			std::cout << "Enter a command : (ADD, SEARCH, EXIT)" << std::endl;
			continue;
		}
		if (command == "ADD")
		{
			phone_book.add_new_contact(phone_book, current_i);
			if (phone_book.total_contacts != 8)
				phone_book.total_contacts++;
			if (current_i == 7)
				current_i = -1;
			current_i++;
		}
		else if (command == "SEARCH")
			phone_book.show_search(phone_book);
 		else if (command == "EXIT")
			break ;
		std::cout << "Enter a command : (ADD, SEARCH, EXIT)" << std::endl;
	}
}
