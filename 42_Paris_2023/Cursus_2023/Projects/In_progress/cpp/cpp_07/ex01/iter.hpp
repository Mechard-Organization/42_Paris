/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:45:35 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 02:45:35 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include <cctype>

/* Codes ANSI pour la couleur du texte */
// Réinitialisation
#define RESET          "\033[0m"

// Couleurs standards du texte
#define BLACK1          "\033[0;30m"
#define RED1            "\033[0;31m"
#define GREEN1          "\033[0;32m"
#define YELLOW1         "\033[0;33m"
#define BLUE1           "\033[0;34m"
#define MAGENTA1        "\033[0;35m"
#define CYAN1           "\033[0;36m"
#define WHITE1          "\033[0;37m"

// Couleurs en gras (couleurs claires)
#define BLACK2     "\033[1;30m"
#define RED2       "\033[1;31m"
#define GREEN2     "\033[1;32m"
#define YELLOW2    "\033[1;33m"
#define BLUE2      "\033[1;34m"
#define MAGENTA2   "\033[1;35m"
#define CYAN2      "\033[1;36m"
#define WHITE2     "\033[1;37m"

template <typename T, typename Func>
void iter(T* array, size_t length, Func func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
