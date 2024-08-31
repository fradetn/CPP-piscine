/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:45:39 by nfradet           #+#    #+#             */
/*   Updated: 2024/08/31 15:56:09 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void search(void);
	void tabContact(void);
	void addContact(void);
	int getNbContact(void);

private:

	int	i;
	int	nbContact;
	Contact contact[8];
};


#endif 

