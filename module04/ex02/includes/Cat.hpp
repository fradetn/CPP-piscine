/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:59:31 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 11:16:04 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{

private:
	Brain *brain;

public:
	Cat(void);
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &rhs);
	void makeSound() const;
};

#endif