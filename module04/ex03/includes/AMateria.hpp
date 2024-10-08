/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:03:58 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/08 14:24:59 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string type;
	bool isEquiped;

public:
    AMateria();
    AMateria(std::string const &_type);
    AMateria(AMateria const &src);
	virtual ~AMateria();

    bool getIsEquiped(void) const;
    void setIsEquiped(bool newVal);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    AMateria &operator=(AMateria const &rhs);
};