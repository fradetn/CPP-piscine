/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:12:18 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 16:03:07 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
 
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &src);
	virtual ~Animal();

	std::string const &getType() const;
	Animal &operator=(Animal const &rhs);

	virtual void makeSound() const = 0;
};


#endif