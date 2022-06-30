/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:08:46 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:27:32 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *const_str1, const char *const_str2)
{
	int		i;

	i = 0;
	if (!const_str1 || !const_str2)
		return (1);
	while (const_str1[i] || const_str2[i])
	{
		if (!const_str1[i] || !const_str2[i] || const_str1[i] != const_str2[i])
			return (1);
		i++;
	}
	return (0);
}
