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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Arthur("Arthur Dent", 1);
    Bureaucrat Humma("Humma Kavula", 150);
	
	std::cout << "--------- Tests ---------" << std::endl;
	std::cout << std::endl;

    try
	{
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        // Arthur signe les formulaires
        Arthur.signForm(shrub);
        Arthur.signForm(robot);
        Arthur.signForm(pardon);

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        // Arthur exécute les formulaires
        Arthur.executeForm(shrub);
        Arthur.executeForm(robot);
        Arthur.executeForm(pardon);

		// Test 1 : Tentavive d'éxecution en Low Grade
        // Humma (grade 150) tente d'éxecuter le formulaire sans avoir le grade adequat

		std::cout << std::endl;
        std::cout << "---- Testing 1 ----" << std::endl;
		std::cout << std::endl;
        Humma.signForm(shrub);
        Humma.executeForm(shrub);

        // Test 2 : Re-signature d'un formulaire déjà signé
        // Ford Prefect (grade 145) signe un ShrubberyCreationForm pour "Milliways"
        // puis Trillian (grade 137) tente de re-signer le même formulaire.
		std::cout << std::endl;
        std::cout << "---- Testing 2 ----" << std::endl;
		std::cout << std::endl;
        Bureaucrat Ford("Ford Prefect", 145);
        Bureaucrat Trillian("Trillian", 137);
        ShrubberyCreationForm shrub2("Milliways");
        Ford.signForm(shrub2);      // Ford signe avec succès (grade requis = 145)
        Trillian.signForm(shrub2);  // Tentative de re-signature (le formulaire est déjà signé)
        std::cout << shrub2 << std::endl;

        // Test 3 : Exécution d'un formulaire non signé
        // Création d'un PresidentialPardonForm pour "Deep Thought" sans signature.
        // Zaphod Beeblebrox (grade 1) tente d'exécuter le formulaire, ce qui doit lever une exception.
		std::cout << std::endl;
        std::cout << "---- Testing 3 ----" << std::endl;
		std::cout << std::endl;
        PresidentialPardonForm pardon2("Deep Thought");
        Bureaucrat Zaphod("Zaphod Beeblebrox", 1);
        Zaphod.executeForm(pardon2); // Exception attendue : formulaire non signé

        // Test 4 : Exécution d'un formulaire avec un grade insuffisant
        // RobotomyRequestForm pour "Gag Halfrunt" signé par Slartibartfast (grade 72),
        // puis tentative d'exécution par Ford Prefect (grade 72) qui est insuffisant pour l'exécution (exec grade = 45).
		std::cout << std::endl;
        std::cout << "---- Testing 4 ----" << std::endl;
		std::cout << std::endl;
        RobotomyRequestForm robot2("Gag Halfrunt");
        Bureaucrat Slart("Slartibartfast", 72);  // Peut signer (grade requis = 72)
        Slart.signForm(robot2);
        Bureaucrat Ford2("Ford Prefect", 72);      // Grade 72, insuffisant pour exécuter (exec grade = 45)
        Ford2.executeForm(robot2); // Exception attendue : grade trop bas pour exécuter

        // Test 5 : Exécution multiple pour observer la robotomisation aléatoire
        // Arthur signe un nouveau RobotomyRequestForm pour "Betelgeuse"
        // et exécute plusieurs fois afin de voir le succès ou l'échec aléatoire.
		std::cout << std::endl;
        std::cout << "---- Testing 5 ----" << std::endl;
		std::cout << std::endl;
        RobotomyRequestForm robot3("Betelgeuse");
        Arthur.signForm(robot3);
        std::cout << "Executing RobotomyRequestForm multiple times to test randomness:" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            Arthur.executeForm(robot3);
        }

        // Test 6 : Exécution avec des grades limites
        // Création d'un PresidentialPardonForm pour "Pan Galactic Gargle Blaster"
        // Fenchurch (grade 25) signe le formulaire et Eddie (grade 5) l'exécute,
        // respectant ainsi les grades limites requis (sign: 25, exec: 5).
		std::cout << std::endl;
        std::cout << "---- Testing 6 ----" << std::endl;
		std::cout << std::endl;
        PresidentialPardonForm pardon3("Pan Galactic Gargle Blaster");
        Bureaucrat Fench("Fenchurch", 25); // Peut signer (grade requis = 25)
        Fench.signForm(pardon3);
        Bureaucrat Eddie("Eddie", 5);      // Peut exécuter (grade requis = 5)
        Eddie.executeForm(pardon3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
