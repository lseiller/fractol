/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:37:25 by lseiller          #+#    #+#             */
/*   Updated: 2022/05/18 16:28:56 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlencut(char *str, char set, size_t size)
{
	size_t	i;
	size_t	len;

	(void)size;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == set && str[i + size])
		{
			len++;
			i++;
		}
		else if (str[i] == set)
			;
		else
			len++;
		i++;
	}
	return (len);
}

char	*ft_strncut(char *str, char set, size_t size)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	dest = ft_calloc(ft_strlencut(str, set, size) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		if (str[i] == set && str[i + size])
			dest[j++] = str[i++];
		else if (str[i] == set)
			;
		else
			dest[j++] = str[i];
		i++;
	}
	return (dest);
}
