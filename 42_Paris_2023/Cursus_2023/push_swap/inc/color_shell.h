/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:59:10 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:12:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_SHELL_H
# define COLOR_SHELL_H
/*
** color letters
*/
# define C_BLACK "\033[30m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"
# define C_BLUE "\033[34m"
# define C_MAGENTA "\033[35m"
# define C_CYAN "\033[36m"
# define C_WHITE "\033[37m"
# define C_GREY "\033[90m"
/*
** color letters Gras
*/
# define C_G_BLACK "\033[30;01m"
# define C_G_RED "\033[31;01m"
# define C_G_GREEN "\033[32;01m"
# define C_G_YELLOW "\033[33;01m"
# define C_G_BLUE "\033[34;01m"
# define C_G_MAGENTA "\033[35;01m"
# define C_G_CYAN "\033[36;01m"
# define C_G_WHITE "\033[37;01m"
# define C_G_GREY "\033[90;01m"
/*
** color background
*/
# define C_B_BLACK "\033[40m"
# define C_B_RED "\033[41m"
# define C_B_GREEN "\033[42m"
# define C_B_YELLOW "\033[43m"
# define C_B_BLUE "\033[44m"
# define C_B_MAGENTA "\033[45m"
# define C_B_CYAN "\033[46m"
# define C_B_WHITE "\033[47m"
# define C_B_GREY "\033[100m"

/*
** default color reset
*/
# define C_RES "\033[0m"

#endif