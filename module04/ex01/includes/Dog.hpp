/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:59:32 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 15:48:51 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
 
private:
	Brain *brain;

public:
	Dog(void);
	Dog(Dog const &src);
	~Dog();

	Dog &operator=(Dog const &rhs);
	void makeSound() const;
};


#endif