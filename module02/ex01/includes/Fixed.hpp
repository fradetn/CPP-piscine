/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:50:03 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/12 20:06:37 by nfradet          ###   ########.fr       */
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

	Fixed &	operator=(Fixed const & rhs);	// Surcharge de l'operateur d'affectation '='

	float toFloat(void) const;
	int toInt( void ) const;
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

	Fixed & operator<<(std::ostream &os, Fixed const & obj);	// Surcharge externe de l'operateur d'insertion '>>'

#endif