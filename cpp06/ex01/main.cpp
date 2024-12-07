/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:08:02 by abablil           #+#    #+#             */
/*   Updated: 2024/12/07 15:28:40 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data = {1337, "Hello, World!"};

	uintptr_t raw = Serializer::serialize(&data);

	Data *deserializedData = Serializer::deserialize(raw);

	if (deserializedData == &data)
		std::cout << "Pointers match!\n";
	else
		std::cout << "Pointers do not match!\n";

	std::cout << "Data number: " << deserializedData->number << "\n";
	std::cout << "Data text: " << deserializedData->text << "\n";

	return 0;
}
