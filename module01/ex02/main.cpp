/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:53:33 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/02 03:28:26 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(){
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Addresses" << std::endl;
	std::cout << "str    : " << &str << std::endl;
	std::cout << "strPTR : " << stringPTR << std::endl;
	std::cout << "strREF : " << &stringREF << std::endl;
	
	std::cout << "Valeurs" << std::endl;
	std::cout << "str    : " << str << std::endl;
	std::cout << "strPTR : " << *stringPTR << std::endl;
	std::cout << "strREF : " << stringREF << std::endl;
}