/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:33:32 by mechard           #+#    #+#             */
/*   Updated: 2025/03/16 11:33:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n--- Test avec ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Cible1");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "\n--- Test avec ScavTrap ---" << std::endl;
    ScavTrap scav("Scavy");
    scav.attack("Cible2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    return 0;
}
