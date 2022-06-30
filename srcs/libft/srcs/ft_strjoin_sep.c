/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:13:38 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/02 16:49:13 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(char const *s1, char const *s2, char sep)
{
	char	*dest;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc((len + 2), sizeof(char));
	if (!dest)
		return (NULL);
	while (*s1)
		*dest++ = *s1++;
	*dest++ = sep;
	while (*s2)
		*dest++ = *s2++;
	return (dest - (len + 1));
}
