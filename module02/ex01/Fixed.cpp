/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:51:03 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/12 20:12:29 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const raw) {

}
Fixed::Fixed(float const raw){

}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->number = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void Fixed::setRawBits(int const raw) {
	this->number = raw;
}

float Fixed::toFloat(void) const {

}
int Fixed::toInt( void ) const {
	
}