/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:55:57 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	int				w;
	unsigned long	nb;

	w = 0;
	if (n < 0)
	{
		nb = -n;
		w += ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb > 9)
		w += ft_putnbr_fd(nb / 10, fd);
	w += ft_putchar_fd(nb % 10 + '0', fd);
	return (w);
}
