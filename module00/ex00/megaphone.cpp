/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:22 by nfradet           #+#    #+#             */
/*   Updated: 2024/06/17 19:48:48 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv){
	
	int 		i;
	std::string	s;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else{
		i = 1;
		while (argv[i]){

			s = argv[i];
			std::cout << std::uppercase << s;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
