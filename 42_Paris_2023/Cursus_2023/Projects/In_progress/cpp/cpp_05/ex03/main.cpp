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

/* ************************************************************************** */
/*                                                                            */
/*   main.cpp                                                                 */
/*   Test de l'Intern pour l'exercice 03                                      */
/*   (H2G2 : Le guide du voyageur intergalactique)                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // ---- Tests existants ----
    try
	{
        Bureaucrat Arthur("Arthur Dent", 1);
        Bureaucrat Humma("Humma Kavula", 150);

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

        std::cout << "---- Testing with low grade bureaucrat ----" << std::endl;
        // Tentative avec Humma : elle ne devrait pas pouvoir exécuter
        Humma.signForm(shrub); // Probablement déjà signé par Arthur
        Humma.executeForm(shrub);
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ---- Tests supplémentaires ----
    std::cout << "\n---- Test 4 : Création répétée de formulaires du même type ----" << std::endl;
    {
        // Utilisation de l'Intern pour créer deux formulaires identiques.
        Intern intern;
        AForm* formA = intern.makeForm("robotomy request", "Vogon");
        AForm* formB = intern.makeForm("robotomy request", "Vogon");
        std::cout << "Adresse formA: " << formA << std::endl;
        std::cout << "Adresse formB: " << formB << std::endl;
        if (formA && formB && formA != formB)
            std::cout << "Les deux formulaires sont créés distinctement." << std::endl;
        delete formA;
        delete formB;
    }

    std::cout << "\n---- Test 5 : Réutilisation de l'Intern pour divers types de formulaires ----" << std::endl;
    {
        // L'intern crée différents types de formulaires avec des cibles variées.
        Intern intern;
        AForm* form1 = intern.makeForm("shrubbery creation", "Earth");
        AForm* form2 = intern.makeForm("robotomy request", "Mars");
        AForm* form3 = intern.makeForm("presidential pardon", "Jupiter");
        if(form1) std::cout << *form1 << std::endl;
        if(form2) std::cout << *form2 << std::endl;
        if(form3) std::cout << *form3 << std::endl;
        delete form1;
        delete form2;
        delete form3;
    }

    std::cout << "\n---- Test 6 : Re-signature d'un formulaire déjà signé ----" << std::endl;
    {
        // Zaphod signe un formulaire de ShrubberyCreationForm et tente de le signer une seconde fois.
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "Betelgeuse");
        Bureaucrat Zaphod("Zaphod Beeblebrox", 1);
        if(form) {
            Zaphod.signForm(*form);
            // Deuxième tentative de signature, ne devrait pas modifier l'état
            Zaphod.signForm(*form);
            Zaphod.executeForm(*form);
        }
        delete form;
    }

    std::cout << "\n---- Test 7 : Exécution d'un formulaire non signé (attendu : exception) ----" << std::endl;
    {
        // Création d'un formulaire sans signature ; l'exécution doit lever une exception.
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Gaudeamus");
        Bureaucrat Trillian("Trillian", 1);
        if(form) {
            // On n'appelle pas signForm(), donc form reste non signé.
            Trillian.executeForm(*form); // Exception attendue : FormNotSignedException
        }
        delete form;
    }

    std::cout << "\n---- Test 8 : Exécution avec un bureaucrate de grade insuffisant ----" << std::endl;
    {
        // Création d'un formulaire de PresidentialPardonForm signé par un bureaucrate compétent,
        // puis tentative d'exécution par un bureaucrate dont le grade est insuffisant.
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Earth");
        Bureaucrat signer("Ford Prefect", 1);
        Bureaucrat executor("Marvin", 150); // Grade trop faible pour exécuter
        if(form) {
            signer.signForm(*form);
            executor.executeForm(*form); // Exception attendue : GradeTooLowException pour l'exécution
        }
        delete form;
    }

    std::cout << "\n---- Test 9 : Création d'un formulaire inconnu ----" << std::endl;
    {
        // Tentative de création d'un formulaire avec un nom non reconnu.
        Intern intern;
        AForm* formInvalid = intern.makeForm("unknown form", "Nowhere");
        if (!formInvalid)
            std::cout << "Aucun formulaire n'a été créé pour 'unknown form'." << std::endl;
    }

    return 0;
}
