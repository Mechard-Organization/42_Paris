/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:34 by mechard           #+#    #+#             */
/*   Updated: 2025/02/12 15:32:37 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact() {
    static int index = 0;
    std::cout << "Adding a new contact..." << std::endl;
    contacts[index % 8].setContact(); // Remplace l'ancien contact si besoin
    index++;
    if (contactCount < 8)
        contactCount++;
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts in the PhoneBook." << std::endl;
        return;
    }
    
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        contacts[i].displayShortInfo(i);
    }

    std::cout << "Enter an index to view details: ";
    int index;
    std::cin >> index;
    std::cin.ignore();
    
    if (index < 0 || index >= contactCount || std::cin.fail()) {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    contacts[index].displayContact();
}
