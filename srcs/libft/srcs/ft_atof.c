/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:39:37 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 23:29:04 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_float_nb(const char *nptr)
{
	char	*atof;
	int		n;
	double	final;

	atof = (char *)nptr;
	final = 0;
	n = 1;
	while ((*atof >= 9 && *atof <= 13) || *atof == ' ')
		atof++;
	if (*atof == '-' || *atof == '+')
	{
		if (*atof == '-')
			n = -1;
		atof++;
	}
	while (*atof >= '0' && *atof <= '9')
		atof++;
	if (*atof == '.')
		atof++;
	while (*atof >= '0' && *atof <= '9')
		atof++;
	atof--;
	while (*atof != '.')
		final = final / 10 + (double)(*atof-- - 48);
	return (n * (final / 10));
}

double	ft_atof(const char *nptr)
{
	char	*atof;
	int		n;
	double	final;

	n = 1;
	final = 0;
	atof = (char *)nptr;
	while ((*atof >= 9 && *atof <= 13) || *atof == ' ')
		atof++;
	if (*atof == '-' || *atof == '+')
	{
		if (*atof == '-')
			n = -1;
		atof++;
	}
	while (*atof >= '0' && *atof <= '9')
		final = final * 10 + (*atof++ - 48);
	return (final * n + ft_float_nb(nptr));
}
