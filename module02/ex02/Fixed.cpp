/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:51:03 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/17 17:32:10 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed(void) {
	this->number = 0;
}

Fixed::Fixed(Fixed const& src) {
	*this = src;
}

Fixed::Fixed(int const raw) {
	this->number = raw << this->bits;
}

Fixed::Fixed(float const raw){
	this->number = roundf(raw * (1 << this->bits));
}

Fixed::~Fixed() {
}


int	Fixed::getRawBits(void) const {
	return (this->number);
}

void Fixed::setRawBits(int const raw) {
	this->number = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->number) / (1 << this->bits));
}

int Fixed::toInt( void ) const {
	return (static_cast<int>(this->number >> this->bits));
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	return ((a < b) ? a : b);
}
Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
	return ((a < b) ? a : b);
}
Fixed & Fixed::max(Fixed & a, Fixed & b) {
	return ((a > b) ? a : b);
}
Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
	return ((a > b) ? a : b);
	
}

Fixed &Fixed::operator=(Fixed const & rhs) {
	this->number = rhs.getRawBits();
	return (*this);
}
Fixed Fixed::operator+(Fixed const & rhs) const {
	Fixed res = Fixed();
	res.setRawBits(this->getRawBits() + rhs.number);
	return (res);
}
Fixed Fixed::operator-(Fixed const & rhs) const {
	Fixed res = Fixed();
	res.setRawBits(this->getRawBits() - rhs.number);
	return (res);
}
Fixed Fixed::operator*(Fixed const & rhs) const {
	Fixed res = Fixed();
	res.setRawBits((this->getRawBits() * rhs.number) >> res.bits);
	return (res);
}
Fixed Fixed::operator/(Fixed const & rhs) const {
	Fixed res = Fixed();
	res.setRawBits((this->getRawBits() >> res.bits) / rhs.number);
	return (res);
}

bool Fixed::operator>(Fixed const & rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}
bool Fixed::operator<(Fixed const & rhs) const {
	return (this->getRawBits() < rhs.getRawBits());
}
bool Fixed::operator>=(Fixed const & rhs) const {
	return (this->getRawBits() >= rhs.getRawBits());
}
bool Fixed::operator<=(Fixed const & rhs) const {
	return (this->getRawBits() <= rhs.getRawBits());
}
bool Fixed::operator==(Fixed const & rhs) const {
	return (this->getRawBits() == rhs.getRawBits());
}
bool Fixed::operator!=(Fixed const & rhs) const {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed & Fixed::operator++() {
	++this->number;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed save = *this;
	++this->number;
	return (save);
}
Fixed & Fixed::operator--() {
	--this->number;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed save = *this;
	--this->number;
	return (save);
}

std::ostream& operator<<(std::ostream &os, Fixed const & obj) {
	os << obj.toFloat();
	return (os);
}