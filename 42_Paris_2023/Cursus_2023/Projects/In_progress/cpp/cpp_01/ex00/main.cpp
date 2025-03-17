/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:22:09 by mechard           #+#    #+#             */
/*   Updated: 2025/03/15 18:57:19 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie* heapZombie = newZombie("Heap_Zombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stack_Zombie");

    return 0;
}
