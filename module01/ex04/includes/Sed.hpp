/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:08:47 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/04 16:46:16 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

class Sed
{
private:
	std::string fileIn;
	std::string fileOut;
	
public:
	Sed(std::string filename);
	~Sed();

	void	replace(std::string toFind, std::string toReplace);
};

