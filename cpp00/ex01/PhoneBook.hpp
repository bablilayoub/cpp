/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:32:25 by abablil           #+#    #+#             */
/*   Updated: 2024/07/04 12:12:53 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		int			total_contacts;
		void		add_new_contact(PhoneBook &phone_book, int current_i);
		void		show_search(PhoneBook &phone_book);
	private:
		Contact		contacts[8];
		void		prompt_search(PhoneBook &phone_book);
		int			valid_input(std::string input, int i);
};