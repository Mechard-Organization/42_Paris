/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:32:48 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:32:48 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat Arthur("Arthur Dent", 2);
        std::cout << Arthur << std::endl;
        Arthur.incrementGrade();
        std::cout << Arthur << std::endl;
        Arthur.incrementGrade();
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

    try
	{
        Bureaucrat Humma("Humma Kavula", 149);
        std::cout << Humma << std::endl;
        Humma.decrementGrade();
        std::cout << Humma << std::endl;
        Humma.decrementGrade();
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}
