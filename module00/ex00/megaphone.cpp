/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:22 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 10:15:46 by nfradet          ###   ########.fr       */
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
			for (size_t j=0; j < s.length(); j++)
				std::cout << (char)std::toupper(s[j]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
