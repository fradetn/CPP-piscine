/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:45:39 by nfradet           #+#    #+#             */
/*   Updated: 2024/08/30 16:49:14 by nfradet          ###   ########.fr       */
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

	void search(void);
	void addContact(void);
	int getNbContact(void);

private:

	int	i;
	int	nbContact;
	Contact contact[8];
};


#endif 

