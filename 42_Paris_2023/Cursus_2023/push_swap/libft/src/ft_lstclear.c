/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:24:44 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:34:24 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*str;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	str = *lst;
	while (str)
	{
		tmp = str->next;
		ft_lstdelone(str, del);
		str = tmp;
	}
	*lst = NULL;
}
