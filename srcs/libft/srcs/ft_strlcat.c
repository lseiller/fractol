/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:21:52 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	sizesrc;
	unsigned int	sizedst;

	i = 0;
	sizesrc = ft_strlen(src);
	sizedst = ft_strlen(dst);
	if (size == 0 || size <= sizedst)
		return (sizesrc + size);
	size = size - sizedst - 1;
	while (i < size && src[i] != '\0')
	{
		dst[i + sizedst] = src[i];
		i++;
	}
	dst[i + sizedst] = '\0';
	return (sizedst + sizesrc);
}
