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
#include "Form.hpp"

int main()
{
    try
	{
        Bureaucrat Arthur("Arthur Dent", 50);
        Form formA("FormA", 100, 100);
        std::cout << Arthur << std::endl;
        std::cout << formA << std::endl;
        Arthur.signForm(formA);
        std::cout << formA << std::endl;
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
        Bureaucrat Humma("Humma Kavula", 150);
        Form formB("FormB", 100, 100);
        std::cout << Humma << std::endl;
        std::cout << formB << std::endl;
        Humma.signForm(formB);
        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
