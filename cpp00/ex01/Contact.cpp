/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:20:26 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 11:30:26 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getValue(std::string name)
{
	if (name == "first_name")
		return first_name;
	if (name == "last_name")
		return last_name;
	if (name == "nickname")
		return nickname;
	if (name == "phone_number")
		return phone_number;
	if (name == "darkest_secret")
		return darkest_secret;
	return NULL;
}

void	Contact::setValue(std::string name, std::string value)
{
	if (name == "first_name")
		first_name = value;
	if (name == "last_name")
		last_name = value;
	if (name == "nickname")
		nickname = value;
	if (name == "phone_number")
		phone_number = value;
	if (name == "darkest_secret")
		darkest_secret = value;
}
