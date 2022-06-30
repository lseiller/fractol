/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:40:04 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:34:11 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (dest);
}
