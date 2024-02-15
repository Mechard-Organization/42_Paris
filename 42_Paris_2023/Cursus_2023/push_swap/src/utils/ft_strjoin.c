/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:43 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:07:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <utils.h>

static void	*join(char **ret, char *arg, int *retsize)
{
	char	*tmp;
	int		size;

	size = ft_strlen(arg);
	tmp = try_malloc(sizeof(char) * (*retsize + size + 1));
	ft_memcpy(tmp, *ret, *retsize);
	ft_memcpy(tmp + *retsize, arg, size);
	*retsize += size;
	tmp[*retsize] = '\0';
	free(*ret);
	*ret = tmp;
	return (tmp);
}

char	*tho(char *arg, char **ret, int *size)
{
	*ret = ft_strdup(arg);
	if (!(*ret))
		return (NULL);
	*size = ft_strlen(*ret);
	return (arg);
}

char	*ft_strjoin(int nb_str, ...)
{
	char	*arg;
	char	*ret;
	va_list	ap;
	int		size;

	ret = NULL;
	size = 0;
	va_start(ap, nb_str);
	while (nb_str--)
	{
		arg = va_arg(ap, char *);
		if (!arg)
			continue ;
		if (!ret)
		{
			if (tho(arg, &ret, &size) == NULL)
				return (NULL);
		}
		else if (join(&ret, arg, &size) == NULL)
			return (NULL);
	}
	va_end(ap);
	return (ret);
}
