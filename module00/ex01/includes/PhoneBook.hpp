/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:45:39 by nfradet           #+#    #+#             */
/*   Updated: 2024/06/17 23:31:19 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	// Contact createContact(void);
	void addContact(void);
	// size_t getNbContact(void);

private:

	int	i;
	Contact contact[8];
};


#endif 

