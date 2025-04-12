/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:29:44 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 00:29:44 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.letter = 'A';

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Adresse originale : " << &data << std::endl;
    std::cout << "Valeur sérialisée : " << raw << std::endl;

    Data* newData = Serializer::deserialize(raw);
    std::cout << "Adresse désérialisée : " << newData << std::endl;
    std::cout << "Données récupérées : number = " << newData->number 
              << ", letter = " << newData->letter << std::endl;

    if (newData == &data)
        std::cout << "La sérialisation/désérialisation a réussi." << std::endl;
    else
        std::cout << "Erreur dans la sérialisation/désérialisation." << std::endl;

    return 0;
}
