/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:13:07 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	s = (char *) src;
	d = (char *) dest;
	if (src > dest)
	{
		while (i < n)
		{
			*(d + i) = *(s + i);
			i++;
		}
		return (dest);
	}
	while (i < n)
	{
		*(d + n - i - 1) = *(s + n - i - 1);
		i++;
	}
	return (dest);
}
