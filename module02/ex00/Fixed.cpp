/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:51:43 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/05 18:05:19 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	this->number = src.number;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->number = rhs.number;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	
}

void Fixed::setRawBits(int const raw) {
	
}