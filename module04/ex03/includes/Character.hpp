/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:40:28 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/02 16:06:55 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include <iostream>

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter{

private:
    std::string name;

public:
    Character();
    Character(std::string const &_name);
    Character(Character const &src);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

    Character &operator=(Character const &rhs);
};
