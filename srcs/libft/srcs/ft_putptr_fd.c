/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:59:43 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	int		a;
	long	address;

	address = (long) ptr;
	if (!address)
		a = ft_putstr_fd(PTR_NULL, fd);
	else
	{
		a = ft_putstr_fd("0x", fd);
		a += ft_puthex_fd(address, 'x', fd, 1);
	}
	return (a);
}
