/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:20:52 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/22 18:42:35 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->stock[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->stock[i] != NULL) {
			delete this->stock[i];
			this->stock[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *mat) {
	for (int i = 0; i < 4; i++) {
		if (this->stock[i] == NULL) {
			this->stock[i] = mat;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->stock[i] != NULL) {
			if (this->stock[i]->getType() == type)
				return (this->stock[i]->clone());
		}
	}
	return (0);
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs) {
	// Clean up the current stock
	for (int i = 0; i < 4; i++) {
		if (this->stock[i] != NULL) {
			delete this->stock[i];
			this->stock[i] = NULL;
		}
	}

	// Deep copy of rhs's stock
	for (int i = 0; i < 4; i++) {
		if (rhs.stock[i] != NULL) {
			this->stock[i] = rhs.stock[i]->clone();
		} else {
			this->stock[i] = NULL;
		}
	}
	return (*this);
}