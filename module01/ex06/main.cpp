/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:32:28 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/05 16:38:43 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

int main(int argc, char **argv) {
	Harl h;

	if (argc != 2) {
		std::cout << "Invalid arguments number (1 argument needed)" << std::endl;
		return (1);
	}
	h.complain(argv[1]);
	return (0);
}