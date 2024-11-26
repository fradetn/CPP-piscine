/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:00:04 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/26 13:54:54 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	uintptr_t serialized;
	Data *data = new Data();
	Data *newData;

	data->name = "John";
	data->age = 21;

	std::cout << "Original Data:" << std::endl;
	std::cout << "name: " << data->name << std::endl;
	std::cout << "age: " << data->age << std::endl;
	std::cout << std::endl;
	serialized = Serializer::serialize(data);
	std::cout << "Serialized data:" << std::endl;
	std::cout << "addr: " << serialized << std::endl;
	std::cout << "value: " << *serialized << std::endl;
	std::cout << std::endl;
	
	newData = Serializer::deserialize(serialized);
	std::cout << "Deserialized data:" << std::endl;
	std::cout << "name: " << newData->name << std::endl;
	std::cout << "age: " << newData->age << std::endl;

	std::cout << std::endl;
	serialized = Serializer::serialize(data);
	std::cout << "Re Serialized data:" << std::endl;
	std::cout << "addr: " << serialized << std::endl;
	std::cout << "value: " << *serialized << std::endl;
	delete data;
}