/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:46 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 10:30:52 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::valid_input(std::string input, int i)
{
	if (i < 2)
		for (int j = 0; j <= i; j++)
			for (int k = 0; input[k]; k++)
				if (!std::isalpha(input[k]) && input[k] != ' ')
					return (0);

	if (i == 2 || i == 3 || i == 4)
		for (int k = 0; input[k]; k++)
		{
			if (!std::isdigit(input[k]) && i == 3)
				return (0);
			if (i == 2 || i == 4)
				if (!std::isdigit(input[k]) && !std::isalpha(input[k]) && input[k] != ' ')
					return (0);
		}
	return (1);
}

void PhoneBook::prompt_search(PhoneBook &phone_book)
{
	std::string input;
	int index = 0;

	if (!phone_book.total_contacts)
		return;
	std::cout << std::endl
			  << "Show a contact info by index:" << std::endl;
	while (std::getline(std::cin, input))
	{
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			std::cout << "input can't be empty" << std::endl;
		else if (input.length() >= 2)
			std::cout << "Invalid input size" << std::endl;
		else if (input[0] < '0' || input[0] > '7')
			std::cout << "Invalid index (from 0 to 7 only)" << std::endl;
		else if (input[0] - '0' > phone_book.total_contacts - 1)
			std::cout << "Contact with this index doese not exist" << std::endl;
		else
		{
			index = input[0] - '0';
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "- First name     : " << phone_book.contacts[index].getValue("first_name") << std::endl;
	std::cout << "- Last name      : " << phone_book.contacts[index].getValue("last_name") << std::endl;
	std::cout << "- Nickname       : " << phone_book.contacts[index].getValue("nickname") << std::endl;
	std::cout << "- Phone number   : " << phone_book.contacts[index].getValue("phone_number") << std::endl;
	std::cout << "- Darkest secret : " << phone_book.contacts[index].getValue("darkest_secret") << std::endl
			  << std::endl;
}

void PhoneBook::show_search(PhoneBook &phone_book)
{
	if (!phone_book.total_contacts)
	{
		std::cout << "No contacts yet !" << std::endl;
		return;
	}
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "|    Index    |  First name  |  Last name   |   Nickname   |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	for (int i = 0; i < phone_book.total_contacts; i++)
	{
		std::cout << "|" << std::setw(13) << i;
		if (phone_book.contacts[i].getValue("first_name").length() > 10)
			std::cout << "|" << std::setw(13) << phone_book.contacts[i].getValue("first_name").substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(14) << phone_book.contacts[i].getValue("first_name");
		if (phone_book.contacts[i].getValue("last_name").length() > 10)
			std::cout << "|" << std::setw(13) << phone_book.contacts[i].getValue("last_name").substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(14) << phone_book.contacts[i].getValue("last_name");
		if (phone_book.contacts[i].getValue("nickname").length() > 10)
			std::cout << "|" << std::setw(13) << phone_book.contacts[i].getValue("nickname").substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << "|" << std::setw(14) << phone_book.contacts[i].getValue("nickname") << "|" << std::endl;
	}
	std::cout << "|----------------------------------------------------------|" << std::endl;
	this->prompt_search(phone_book);
}

void PhoneBook::add_new_contact(PhoneBook &phone_book, int current_i)
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
				phone_book.contacts[current_i].setValue("first_name", input);
			else if (i == 1)
				phone_book.contacts[current_i].setValue("last_name", input);
			else if (i == 2)
				phone_book.contacts[current_i].setValue("nickname", input);
			else if (i == 3)
				phone_book.contacts[current_i].setValue("phone_number", input);
			else if (i == 4)
				phone_book.contacts[current_i].setValue("darkest_secret", input);
			break;
		}
	}
}
