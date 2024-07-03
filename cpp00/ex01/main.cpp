/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:37:38 by abablil           #+#    #+#             */
/*   Updated: 2024/06/10 18:18:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::total_contacts = 0;

int main()
{
	PhoneBook	phone_book;
	int			current_i;

	current_i = 0;
	std::string command;
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
			if (PhoneBook::total_contacts != 8)
				PhoneBook::total_contacts++;
			current_i = (current_i + 1) % 8;
		}
		else if (command == "SEARCH")
			phone_book.show_search(phone_book);
 		else if (command == "EXIT")
			break ;
		else
			std::cout << "Not a valid command" << std::endl;
		std::cout << "Enter a command : (ADD, SEARCH, EXIT)" << std::endl;
	}
}
