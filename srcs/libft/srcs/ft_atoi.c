/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:39:37 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:08:58 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*atoi;
	int		n;
	int		final;

	n = 1;
	final = 0;
	atoi = (char *)nptr;
	while ((*atoi >= 9 && *atoi <= 13) || *atoi == ' ')
		atoi++;
	if (*atoi == '-' || *atoi == '+')
	{
		if (*atoi == '-')
			n = -1;
		atoi++;
	}
	while (*atoi >= '0' && *atoi <= '9')
		final = final * 10 + (*atoi++ - 48);
	return (final * n);
}
