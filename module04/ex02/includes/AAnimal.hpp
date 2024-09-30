/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:12:18 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 16:03:07 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
 
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(AAnimal const &src);
	virtual ~AAnimal();

	std::string const &getType() const;
	AAnimal &operator=(AAnimal const &rhs);

	virtual void makeSound() const = 0;
};


#endif