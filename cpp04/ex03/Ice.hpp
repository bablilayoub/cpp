/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:53:53 by abablil           #+#    #+#             */
/*   Updated: 2024/11/05 15:12:38 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &obj);
	Ice &operator=(const Ice &obj);
	Ice(std::string const &type);
	AMateria* clone() const;
	void use(ICharacter& target);
};