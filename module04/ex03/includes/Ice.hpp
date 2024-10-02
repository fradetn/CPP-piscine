/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:00:22 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/02 16:00:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
protected:
    std::string type;

public:
    Ice();
    Ice(std::string const &_type);
    Ice(Ice const &src);

    std::string const & getType() const; //Returns the materia type
    AMateria* clone() const;
    void use(ICharacter& target);

    Ice &operator=(Ice const &rhs);
};