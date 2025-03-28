/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:47:55 by mechard           #+#    #+#             */
/*   Updated: 2025/03/28 16:47:55 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Fonction utilitaire améliorée pour supprimer espaces, tabulations, retours chariot et sauts de ligne
std::string trim(const std::string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

// Vérifie que la date est au format YYYY-MM-DD et que mois/jour sont plausibles
bool isValidDate(const std::string &date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

// Vérifie que la chaîne représente un nombre positif sans signe (entier ou flottant)
bool isValidNumber(const std::string &numStr) {
    bool dotFound = false;
    for (size_t i = 0; i < numStr.size(); ++i) {
        // On n'autorise pas le signe '+' dans cette fonction
        if (numStr[i] == '.') {
            if (dotFound)
                return false;
            dotFound = true;
        } else if (!std::isdigit(numStr[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    // Charger la base de données depuis "data.csv" (fournie avec le sujet)
    BitcoinExchange be("data.csv");
    if (!be.isDatabaseLoaded()) {
        std::cerr << "Error: database not loaded." << std::endl;
        return 1;
    }
    
    std::string line;
    // Ignore la première ligne si elle contient "date"
    if (std::getline(infile, line)) {
        if (line.find("date") != std::string::npos)
            ; // on ignore le header
        else {
            infile.clear();
            infile.seekg(0, std::ios::beg);
        }
    }
    
    while (std::getline(infile, line)) {
        if (line.empty())
            continue;
        // Découpage en cherchant le caractère '|'
        size_t pos = line.find("|");
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string datePart = trim(line.substr(0, pos));
        std::string valuePart = trim(line.substr(pos + 1));
        
        // Vérification du champ date
        if (!isValidDate(datePart)) {
            std::cout << "Error: bad input => " << datePart << std::endl;
            continue;
        }
        // Vérification spécifique pour les nombres négatifs
        if (!valuePart.empty() && valuePart[0] == '-') {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        // Ensuite, vérification du format numérique (sans signe)
        if (!isValidNumber(valuePart)) {
            std::cout << "Error: bad input => " << valuePart << std::endl;
            continue;
        }
        double value = atof(valuePart.c_str());
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        double rate;
        if (!be.getExchangeRate(datePart, rate)) {
            std::cout << "Error: bad input => " << datePart << std::endl;
            continue;
        }
        double result = value * rate;
        std::cout << datePart << " => " << value << " = " << result << std::endl;
    }
    
    return 0;
}
