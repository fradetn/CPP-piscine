/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:19:02 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/24 20:57:01 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Wrong number of argument, only one argument is expected" << std::endl;
		return (1);
	}

	ScalarConvert::convert(argv[1]);
	return (0);
}