/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:23:08 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/04 18:00:28 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Wrong arguments number (need 3 arguments)" << std::endl;
		return EXIT_FAILURE;
	}
	else {
		Sed sed = Sed(argv[1]);
		sed.replace(argv[2], argv[3]);
	}
	return EXIT_SUCCESS;
}
