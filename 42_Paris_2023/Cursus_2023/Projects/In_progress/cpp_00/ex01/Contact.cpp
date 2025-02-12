/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:20:55 by mechard           #+#    #+#             */
/*   Updated: 2025/02/12 15:35:58 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

void	Contact::setContact()
{
	std::cout << "First Name : ";
	std::getline(std::cin, firstName);

	std::cout << "Last Name : ";
	std::getline(std::cin, lastName);

	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);

	std::cout << "Phone Number : ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, darkestSecret);
}

void	Contact::displayContact() const
{
	std::cout << "First Name : " << firstName << std::endl;

	std::cout << "Last Name : " << lastName << std::endl;

	std::cout << "Nickname : " << nickname << std::endl;

	std::cout << "Phone Number : " << phoneNumber << std::endl;

	std::cout << "Darkest secret : " << darkestSecret << std::endl;
}

void	Contact::displayShortInfo(int index) const
{
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0,9) + "." : firstName) << "|";
	std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0,9) + "." : lastName) << "|";
	std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0,9) + "." : nickname) << "|" << std::endl;
}
