/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:38:57 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(long nbr, char *base, int fd)
{
	unsigned long	num;
	int				c_printed;

	c_printed = 0;
	if (ft_check_base(base) == 1)
	{
		if (nbr < 0)
		{
			num = -nbr;
			c_printed += ft_putchar_fd('-', fd);
		}
		else
			num = nbr;
		if (num >= ft_strlen(base))
			c_printed += ft_putnbr_base_fd((num / ft_strlen(base)), base, fd);
		c_printed += ft_putchar_fd(base[num % ft_strlen(base)], fd);
	}
	return (c_printed);
}
