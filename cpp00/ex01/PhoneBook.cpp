/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:46 by abablil           #+#    #+#             */
/*   Updated: 2024/06/10 18:13:40 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::valid_input(std::string input, int i)
{
	// return (1);
	if (i < 2)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; input[k]; k++)
			{
				if (!std::isalpha(input[k]))
					return (0);
			}
		}
	}
	if (i == 2 || i == 3 || i == 4)
	{
		for (int k = 0; input[k]; k++)
		{
			if (!std::isdigit(input[k]) && i == 3)
				return (0);
			if (i == 2 || i == 4)
			{
				if (!std::isdigit(input[k]) && !std::isalpha(input[k]))
					return (0);
			}
		}
	}
	return (1);
}

void	PhoneBook::show_search(PhoneBook &phone_book)
{
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "|    Index    |  First name  |  Last name   |   Nickname   |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	for (int i = 0; i < phone_book.total_contacts; i++)
	{
		std::cout << "|" << std::setw(13) << i;
		if (phone_book.contacts[i].first_name.length() > 10)
			std::cout << "|" << std::setw(13) << phone_book.contacts[i].first_name.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(14) << phone_book.contacts[i].first_name;
		if (phone_book.contacts[i].last_name.length() > 10)
			std::cout << "|" << std::setw(13) << phone_book.contacts[i].last_name.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(14) << phone_book.contacts[i].last_name;
		if (phone_book.contacts[i].nickname.length())
			std::cout << "|" << std::setw(13) << phone_book.contacts[i].nickname.substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << "|" << std::setw(14) << phone_book.contacts[i].nickname << "|" << std::endl;
	}
	std::cout << "|----------------------------------------------------------|" << std::endl;
}

void	PhoneBook::add_new_contact(PhoneBook &phone_book, int current_i)
{
	std::string fields[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string input;
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter your " << fields[i] << " :" << std::endl;
		while (1)
		{
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit(1);
			if (input.empty())
			{
				std::cout << "Enter your " << fields[i] << " :" << std::endl;
				continue;
			}
			if (!valid_input(input, i))
			{
				std::cout << "Not a valid input" << std::endl;
				std::cout << "Enter your " << fields[i] << " :" << std::endl;
				continue;
			}
			if (i == 0)	
				phone_book.contacts[current_i].first_name = input;
			else if (i == 1)
				phone_book.contacts[current_i].last_name = input;
			else if (i == 2)
				phone_book.contacts[current_i].nickname = input;
			else if (i == 3)
				phone_book.contacts[current_i].phone_number = input;
			else if (i == 4)
				phone_book.contacts[current_i].darkest_secret = input;
			break;
		}
	}
}
