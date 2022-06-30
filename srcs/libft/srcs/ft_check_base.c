/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:34:44 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[++i])
	{
		j = i;
		while (base[++j])
		{
			if ((base[i] == base[j] && j != i)
				|| base[j] == '-' || base[j] == '+')
				return (0);
		}
	}
	return (1);
}
