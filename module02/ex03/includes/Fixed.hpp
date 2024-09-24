/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:50:03 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/24 11:44:13 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int number;
	static int const bits = 8;

public:
	Fixed(void);							// Constructeur par default
	Fixed(int const raw);					// Constructeur avec un entier
	Fixed(float const raw);					// Constructeur avec un flottant
	Fixed(Fixed const & src);				// Constructeur de copie
	~Fixed();								// Destructeur

	/*		Surcharges		*/
	Fixed &operator=(Fixed const & rhs);	// Surcharge de l'operateur d'affectation '='
	
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);


	float toFloat(void) const;
	int toInt( void ) const;
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float abs(void);

	static Fixed & min(Fixed & a, Fixed & b);
	static Fixed const & min(Fixed const & a, Fixed const & b);
	static Fixed & max(Fixed & a, Fixed & b);
	static Fixed const & max(Fixed const & a, Fixed const & b);
};

std::ostream& operator<<(std::ostream &os, Fixed const & obj);	// Surcharge externe de l'operateur d'insertion '>>'

#endif