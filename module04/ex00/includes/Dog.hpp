/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:59:32 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/22 17:51:23 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
 

public:
	Dog(void);
	Dog(Dog const &src);
	~Dog();

	Dog &operator=(Dog const &rhs);
	void makeSound() const;
};


#endif