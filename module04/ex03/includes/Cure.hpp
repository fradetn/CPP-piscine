/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:00:12 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/03 16:25:06 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{

public:
    Cure();
    Cure(std::string const &_type);
    Cure(Cure const &src);

    std::string const & getType() const; //Returns the materia type
    AMateria* clone() const;
    void use(ICharacter& target);

    Cure &operator=(Cure const &rhs);
};
