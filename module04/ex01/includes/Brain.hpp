/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:53:51 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 11:56:42 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(Brain const &src);
    ~Brain();

    std::string const (&getIdeas(void) const)[100];

    Brain &operator=(Brain const &rhs);
};

#endif