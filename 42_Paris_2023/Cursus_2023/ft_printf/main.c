/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:36:13 by mechard           #+#    #+#             */
/*   Updated: 2023/11/27 14:36:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(int ac, char **av)
{
	int		*bf;
	char	*af;
	int		i;
	
	i = -1;
	bf = &i;
	ft_putstr_fd("<------------------Test 1------------------>\n", 0);
	ft_printf("ft_printf = %s %s %conde %s%d \n", av[1], av[2], 'm', av[3], -1);
	printf("printf = %s %s %conde %s%d \n", av[1], av[2], 'm', av[3], -1);
	ft_putstr_fd("<------------------Test 2------------------>\n", 0);
	ft_printf("-ft_printf-1-\np = %p\ni = %i\nu = %u\nx = %x\nX = %X\n%% = %%\n", bf, -20, -20, 230, 230);
	ft_printf("-ft_printf-2-\np = %p\n", af);
	printf("-printf-1-\np = %p\ni = %i\nu = %u\nx = %x\nX = %X\n%% = %%\n", bf, -20, -20, 230, 230);
	printf("-printf-2-\np = %p\n", af);
	ft_putstr_fd("<------------------Test 3------------------>\n", 0);
	ft_printf("-ft_printf-1- \\t = \"\t\"\n");
	printf("-printf-1- \\t = \"\t\"\n");
	ft_putstr_fd("<------------------Test 4------------------>\n", 0);
	ft_printf("-ft_printf-1-\n#x = %#x\n#X = %#X\n", 230, 230);
	printf("-printf-1-\n#x = %#x\n#X = %#X\n", 230, 230);
	ft_putstr_fd("<------------------Test 5------------------>\n", 0);
	ft_printf("-ft_printf-1-\n+i = %+i\n+d = %+d\n", 230, -230);
	printf("-printf-1-\n+i = %+i\n+d = %+d\n", 230, -230);
	ft_printf("-ft_printf-1-\ni = %i et d = %d\n i = % i\n d = % d\n", 230, -230, 230, -230);
	printf("-printf-1-\ni = %i et d = %d\n i = % i\n d = % d\n", 230, -230, 230, -230);
	return (0);
}
