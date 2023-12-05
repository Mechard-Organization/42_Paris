/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:36:13 by mechard           #+#    #+#             */
/*   Updated: 2023/12/05 16:15:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		*bf;
	char	*af;
	int		i;

	i = -1;
	bf = &i;
	if (ac == 0)
		ft_putstr_fd("Printf needs arguments", 0);
	af = "Bon";
	(void)av;
	// ft_putstr_fd("<------------------Test 1------------------>\n", 0);
	// ft_printf("ft_printf = %s %s %conde %s%d \n", av[1], av[2], 'm', av[3],-1);
	// printf("printf = %s %s %conde %s%d \n", av[1], av[2], 'm', av[3], -1);
	// ft_putstr_fd("<------------------Test 2------------------>\n", 0);
	// ft_printf("-ft_printf-1-\np = %p\ni = %i\nu = %u\nx = %x\nX = %X\n%% = %%\n", bf, -20, -20, 230, 230);
	// ft_printf("-ft_printf-2-\np = %p\n", af);
	// printf("-printf-1-\np = %p\ni = %i\nu = %u\nx = %x\nX = %X\n%% = %%\n",bf, -20, -20, 230, 230);
	// printf("-printf-2-\np = %p\n", af);
	// ft_putstr_fd("<------------------Test 3------------------>\n", 0);
	// ft_printf("-ft_printf-1- \\t = \"\t\"\n");
	// printf("-printf-1- \\t = \"\t\"\n");
	// ft_putstr_fd("<------------------Test 4------------------>\n", 0);
	// ft_printf("-ft_printf-1-\n#x = %#x\n#X = %#X\n", 230, 230);
	// printf("-printf-1-\n#x = %#x\n#X = %#X\n", 230, 230);
	// ft_putstr_fd("<------------------Test 5------------------>\n", 0);
	// ft_printf("-ft_printf-1-\n+i = %+i\n+d = %+d\n", 230, -230);
	// printf("-printf-1-\n+i = %+i\n+d = %+d\n", 230, -230);
	// ft_printf("-ft_printf-1-\ni = %i et d = %d\n i = % i\n d = % d\n", 230, 230, 230, 230);
	// printf("-printf-1-\ni = %i et d = %d\n i = %   i\n d = % d\n", 230, 230, 230, 230);
	// ft_putstr_fd("<------------------Test 6------------------>\n", 0);
	// ft_printf("-ft_printf-1- %%10d = %10d\n", -0);
	// printf("-printf-1- %%10d = %10d\n", -0);
	// ft_printf("-ft_printf-1- %%10i = %10i\n", -0);
	// printf("-printf-1- %%10i = %10i\n", -0);
	// ft_printf("\"% 1s\"\n", "");
	// printf("1s = \"%2s\"\n", "");
	// printf("s = \"%s\"\n", "");
	ft_printf("\n#x de 0 = \" %#x\"\n", 0);
	ft_printf("\n#X de 0 = \" %#X\"\n", 0);
	printf("\n#x de 0 = \" %#x\"\n", 0);
	printf("\n#X de 0 = \" %#X\"\n", 0);
	return (0);
}
