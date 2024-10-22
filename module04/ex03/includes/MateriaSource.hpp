/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:34:55 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/22 18:38:47 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include <iostream>

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

private:
	AMateria *stock[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const & src);
	~MateriaSource();
	
	void learnMateria(AMateria *mat);
	AMateria* createMateria(std::string const & type);

	MateriaSource &operator=(MateriaSource const &rhs);
};

