/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:02:04 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:47:15 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_strnbr(int n, char *dest, int index, int len)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		dest[index - 1] = '-';
	}
	else
		nb = n;
	if (nb > 9)
		ft_strnbr(nb / 10, dest, index + 1, len);
	dest[len - index] = (nb % 10 + '0');
}

char	*ft_itoa(int n)
{
	int		index;
	char	*dest;
	int		len;

	len = ft_intlen(n);
	index = 1;
	dest = ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return (NULL);
	ft_strnbr(n, dest, index, len);
	return (dest);
}
