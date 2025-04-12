/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:52:16 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 01:52:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
    Base* p = generate();
    
    std::cout << "Identification via pointeur: ";
    identify(p);
    
    std::cout << "Identification via référence: ";
    identify(*p);
    
    delete p;
    return 0;
}
