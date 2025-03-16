/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:52:30 by mechard           #+#    #+#             */
/*   Updated: 2025/03/16 08:52:30 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

	std::cout << std::endl;
    harl.complain("DEBUG");

	std::cout << std::endl;
    harl.complain("INFO");

	std::cout << std::endl;
    harl.complain("WARNING");

	std::cout << std::endl;
    harl.complain("ERROR");

	std::cout << std::endl;
	std::cout << "[ UNKNOWN ]" << std::endl;
    harl.complain("UNKNOWN");

	std::cout << std::endl;
	std::cout << "[ WHATEVERYOUWANT ]" << std::endl;
    harl.complain("WHATEVERYOUWANT");

    return 0;
}
