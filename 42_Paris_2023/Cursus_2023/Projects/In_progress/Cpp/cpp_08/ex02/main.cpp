/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:12:13 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 09:12:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	// ---------------- Test 1 : Push, Top, Pop, Size ----------------
	std::cout << YELLOW2 << "----------------Test 1----------------" << RESET << std::endl;
	try {
		MutantStack<int> ms;
		ms.push(10);
		ms.push(20);
		ms.push(30);
		std::cout << GREEN2 << "Top element: " << BLUE2 << ms.top() << RESET << std::endl; // Attendu : 30
		ms.pop();
		std::cout << GREEN2 << "Size after pop: " << BLUE2 << ms.size() << RESET << std::endl; // Attendu : 2
	}
	catch (std::exception &e) {
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// ---------------- Test 2 : Itération (begin/end) ----------------
	std::cout << YELLOW2 << "\n----------------Test 2----------------" << RESET << std::endl;
	try {
		MutantStack<int> ms;
		ms.push(5);
		ms.push(15);
		ms.push(25);
		ms.push(35);
		std::cout << GREEN2 << "Contenu de la MutantStack: " << RESET;
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
			std::cout << BLUE2 << *it << RESET << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// ---------------- Test 3 : Itération inverse (rbegin/rend) ----------------
	std::cout << YELLOW2 << "\n----------------Test 3----------------" << RESET << std::endl;
	try {
		MutantStack<int> ms;
		ms.push(100);
		ms.push(200);
		ms.push(300);
		ms.push(400);
		std::cout << GREEN2 << "Contenu inversé de la MutantStack: " << RESET;
		for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
			std::cout << BLUE2 << *rit << RESET << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// ---------------- Test 4 : Constructeur par copie ----------------
	std::cout << YELLOW2 << "\n----------------Test 4----------------" << RESET << std::endl;
	try {
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(3);
		MutantStack<int> msCopy(ms); // Copie via le constructeur par copie
		std::cout << GREEN2 << "Contenu de la copie: " << RESET;
		for (MutantStack<int>::iterator it = msCopy.begin(); it != msCopy.end(); ++it)
			std::cout << BLUE2 << *it << RESET << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// ---------------- Test 5 : Opérateur d'affectation ----------------
	std::cout << YELLOW2 << "\n----------------Test 5----------------" << RESET << std::endl;
	try {
		MutantStack<int> ms1;
		ms1.push(7);
		ms1.push(14);
		ms1.push(21);
		MutantStack<int> ms2;
		ms2 = ms1;
		std::cout << GREEN2 << "Contenu de ms2 après affectation: " << RESET;
		for (MutantStack<int>::iterator it = ms2.begin(); it != ms2.end(); ++it)
			std::cout << BLUE2 << *it << RESET << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// ---------------- Test 6 : Compatibilité avec std::stack ----------------
	std::cout << YELLOW2 << "\n----------------Test 6----------------" << RESET << std::endl;
	try {
		MutantStack<int> ms;
		ms.push(50);
		ms.push(60);
		ms.push(70);
		std::stack<int> s(ms);
		std::cout << GREEN2 << "Taille de std::stack copiée: " << BLUE2 << s.size() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	return 0;
}
