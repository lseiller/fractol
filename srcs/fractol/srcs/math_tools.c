/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 22:36:36 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	power_complex(t_complex_nbr *z)
{
	double	facto_tmp[3];

	facto_tmp[0] = z->real * z->real;
	facto_tmp[1] = z->real * z->imag * 2;
	facto_tmp[2] = z->imag * z->imag;
	z->real = facto_tmp[0] - (facto_tmp[2]);
	z->imag = facto_tmp[1];
}

void	absolute_power_complex(t_complex_nbr *z)
{
	double	facto_tmp[3];

	facto_tmp[0] = fabs(z->real) * fabs(z->real);
	facto_tmp[1] = fabs(z->real) * fabs(z->imag) * 2;
	facto_tmp[2] = fabs(z->imag) * fabs(z->imag);
	z->real = facto_tmp[0] - (facto_tmp[2]);
	z->imag = facto_tmp[1];
}
