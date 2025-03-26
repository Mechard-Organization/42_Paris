/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:01:14 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 06:01:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// ------------------
// Fonctions de test
// ------------------

void printInt(const int &elem) {
    std::cout << elem << " ";
}

void incrementInt(int &elem) {
    elem++;
}

void multiplyInt(int &elem) {
    elem *= 2;
}

void printString(const std::string &s) {
    std::cout << s << " ";
}

void toUpperCase(std::string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = std::toupper(s[i]);
    }
}

void appendSuffix(std::string &s) {
    s += "_SUFFIX";
}

// ------------------
// Fonction main
// ------------------
int main(void)
{
	// Test avec des entiers
	std::cout << "---------First part : Integer---------" << std::endl;
    // Test 1 : Affichage d'un tableau d'entiers
	std::cout << "----------------Test 1----------------" << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << YELLOW2 << "Test 1 - Affichage du tableau d'entiers : " << std::endl << BLUE2 << "[ ";
    iter(arr1, size1, printInt);
    std::cout << RESET << "]" << std::endl << std::endl;
    
    // Test 2 : Incrémenter chaque entier du tableau
	std::cout << "----------------Test 2----------------" << std::endl;
    int arr2[] = {10, 20, 30, 40, 50};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << YELLOW2 << "Test 2 - Incrémentation du tableau d'entiers : " << std::endl << GREEN2 << "avant :" << RESET << std::endl << "[ " << BLUE2;
    iter(arr2, size2, printInt);
	iter(arr2, size2, incrementInt);
	std::cout << RESET << "]" << std::endl << GREEN2 << "aprés :" << RESET << std::endl << "[ " << BLUE2;
	iter(arr2, size2, printInt);
    std::cout << RESET << "]" << std::endl << std::endl;
    
    // Test 3 : Multiplier chaque entier du tableau par 2
	std::cout << "----------------Test 3----------------" << std::endl;
    int arr3[] = {5, 7, 9, 10, 15};
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
	std::cout << YELLOW2 << "Test 3 - Multiplication par 2 du tableau d'entiers : " << std::endl << GREEN2 << "avant :" << RESET << std::endl << "[ " << BLUE2;
    iter(arr2, size2, printInt);
    iter(arr3, size3, multiplyInt);
	std::cout << RESET << "]" << std::endl << GREEN2 << "aprés :" << RESET << std::endl << "[ " << BLUE2;
    iter(arr3, size3, printInt);
    std::cout << RESET << "]" << std::endl << std::endl;
    
	// Test avec des chaînes de caractères
	std::cout << std::endl << "---------Second part : String---------" << std::endl;
    // Test 4 : Affichage d'un tableau de chaînes
	std::cout << "----------------Test 4----------------" << std::endl;
    std::string arr4[] = {"hello", "world", "42"};
    size_t size4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << YELLOW2 << "Test 4 - Affichage du tableau de chaînes : " << RESET << std::endl << "[ " << BLUE2;
    iter(arr4, size4, printString);
	std::cout << RESET << "]" << std::endl << std::endl;
    
    // Test 5 : Conversion en majuscules d'un tableau de chaînes
	std::cout << "----------------Test 5----------------" << std::endl;
    std::string arr5[] = {"foo", "bar", "baz"};
    size_t size5 = sizeof(arr5) / sizeof(arr5[0]);
    std::cout << YELLOW2 << "Test 5 - Conversion en majuscules du tableau de chaînes : " << std::endl << GREEN2 << "avant :" << RESET << std::endl << "[ " << BLUE2;
    iter(arr5, size5, printString);
    iter(arr5, size5, toUpperCase);
	std::cout << RESET << "]" << std::endl << GREEN2 << "aprés :" << RESET << std::endl << "[ " << BLUE2;
	iter(arr5, size5, printString);
    std::cout << RESET << "]" << std::endl << std::endl;
    
    // Test 6 : Ajout d'un suffixe à chaque chaîne du tableau
	std::cout << "----------------Test 6----------------" << std::endl;
    std::string arr6[] = {"alpha", "beta", "gamma"};
    size_t size6 = sizeof(arr6) / sizeof(arr6[0]);
    std::cout << YELLOW2 << "Test 6 - Ajout d'un suffixe au tableau de chaînes : " << std::endl << GREEN2 << "avant :" << RESET << std::endl << "[ " << BLUE2;
    iter(arr6, size6, printString);
    iter(arr6, size6, appendSuffix);
	std::cout << RESET << "]" << std::endl << GREEN2 << "aprés :" << RESET << std::endl << "[ " << BLUE2;
	iter(arr6, size6, printString);
    std::cout << RESET << "]" << std::endl << std::endl;
    
    return 0;
}