/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:32:25 by abablil           #+#    #+#             */
/*   Updated: 2024/06/10 18:13:43 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		void		add_new_contact(PhoneBook &phone_book, int current_i);
		void		show_search(PhoneBook &phone_book);
		static int	total_contacts;
		Contact		contacts[8];
	private:
		int		valid_input(std::string input, int i);
};
