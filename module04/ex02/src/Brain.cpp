/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:16:33 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 11:56:38 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
}

Brain::Brain(Brain const &src) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string const (&Brain::getIdeas(void) const)[100] {
    return (this->ideas);
}

Brain &Brain::operator=(Brain const &rhs) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i];
    return (*this);
}