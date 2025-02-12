/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:46:36 by mechard           #+#    #+#             */
/*   Updated: 2025/02/03 13:49:30 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

// Fonction pour afficher un message d'erreur sur la sortie d'erreur standard et retourner 1
int err(char *str)
{
    while (*str) // Tant que le caractère courant n'est pas le caractère de fin de chaîne
        write(2, str++, 1); // Écrit le caractère actuel sur la sortie d'erreur standard et avance dans la chaîne
    return 1; // Retourne 1 pour indiquer une erreur
}

// Fonction pour changer de répertoire avec la commande 'cd'
int cd(char **argv, int i)
{
    return i != 2 ? err("error: cd: bad arguments\n") // Si le nombre d'arguments est différent de 2, retourne une erreur
    : (chdir(argv[1]) == -1 ? err("error: cd: cannot change directory to "), err(argv[1]), err("\n") : 0); // Sinon, change le répertoire et retourne une erreur si cela échoue
}

// Fonction pour exécuter une commande avec ou sans pipe
int exec(char **argv, char **envp, int i)
{
    int fd[2], status, has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (has_pipe && pipe(fd) == -1) return err("error: fatal\n"); // Crée un pipe si nécessaire et retourne une erreur en cas d'échec

    int pid = fork(); // Crée un processus enfant
    if (!pid) // Dans le processus enfant
    {
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) || close(fd[1]))) return err("error: fatal\n"); // Configure le pipe si nécessaire et retourne une erreur en cas d'échec
        execve(*argv, argv, envp); // Exécute la commande et retourne une erreur si l'exécution échoue
        return err("error: cannot execute "), err(*argv), err("\n");
    }
    waitpid(pid, &status, 0); // Attend la fin du processus enfant
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) || close(fd[1]))) return err("error: fatal\n"); // Configure le pipe pour le processus parent si nécessaire et retourne une erreur en cas d'échec
    return WIFEXITED(status) && WEXITSTATUS(status); // Retourne le statut de sortie du processus enfant
}

// Fonction principale
int main(int argc, char **argv, char **envp)
{
    int i = 0, status = 0;
    while (argc > 1 && argv[i] && argv[++i]) // Boucle tant qu'il y a des arguments à traiter
    {
        argv += i; i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";")) i++; // Parcourt les arguments jusqu'à trouver un pipe '|' ou un point-virgule ';'
        if (!strcmp(*argv, "cd")) status = cd(argv, i); // Exécute 'cd' ou une autre commande en fonction de l'argument actuel
        else if (i) status = exec(argv, envp, i);
    }
    return status; // Retourne le statut final
}
