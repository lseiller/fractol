/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:20:51 by lseiller          #+#    #+#             */
/*   Updated: 2022/05/30 15:53:21 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_set(char const *s, unsigned int start, char set)
{
	char	*strmalloc;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != set)
		len ++;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (len >= ft_strlen(s + start))
		strmalloc = ft_calloc((ft_strlen(s + start) + 1), sizeof(char));
	else
		strmalloc = ft_calloc((len + 1), sizeof(char));
	if (strmalloc == NULL)
		return (NULL);
	ft_strlcpy(strmalloc, s + start, len + 1);
	return (strmalloc);
}
