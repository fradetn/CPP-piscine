/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:12:18 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/22 08:17:27 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostram>
#include <string>

class Animal {
 
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &src);
	~Animal();

	Animal &operator=(Animal const &rhs);
};

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}


#endif