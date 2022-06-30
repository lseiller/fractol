/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:25 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:39:09 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!big || !little || !*little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		k = i;
		while (big[k] == little[j] && k < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *) big + (k - j + 1));
			k++;
		}
		i++;
	}
	return (NULL);
}
