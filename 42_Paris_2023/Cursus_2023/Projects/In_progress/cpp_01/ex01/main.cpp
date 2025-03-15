/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:42:22 by mechard           #+#    #+#             */
/*   Updated: 2025/03/15 18:42:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

Zombie* zombieHorde(int N, std::string name);

int main(int ac, char **av)
{
    if (ac != 3)
	{
        std::cerr << "Usage: " << av[0] << " <nombre_de_zombies> <nom_du_zombie>" << std::endl;
        return 1;
    }
    int N = std::atoi(av[1]);
    if (N <= 0)
	{
        std::cerr << "Le nombre de zombies doit être un entier positif." << std::endl;
        return 1;
    }
    Zombie* horde = zombieHorde(N, av[2]);
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete [] horde;
    return 0;
}
