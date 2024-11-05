/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:28:22 by abablil           #+#    #+#             */
/*   Updated: 2024/11/05 15:12:08 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ICharacter;
class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &obj);
	AMateria &operator=(const AMateria &obj);
	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};