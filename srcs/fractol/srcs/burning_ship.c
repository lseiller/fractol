/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:45:37 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 23:05:02 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship_set(t_data mlx_data, int x, int y)
{
	int				color;
	size_t			i;
	t_complex_nbr	z;
	t_complex_nbr	constant;

	constant.real = (mlx_data.boundary_x) + x / (WIN_SIZE / mlx_data.size);
	constant.imag = (mlx_data.boundary_y) - y / (WIN_SIZE / mlx_data.size);
	z.real = 0;
	z.imag = 0;
	color = 0x00000000;
	i = 0;
	while (i < mlx_data.precision && mlx_data.precision > 0)
	{
		absolute_power_complex(&z);
		z.real -= constant.real;
		z.imag -= constant.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
		{
			color = mlx_data.color.color_tab[mlx_data.color.color_select] * i;
			break ;
		}
		i++;
	}
	img_pix_put(&mlx_data.img, x, y, color);
}

void	burning_julia_set(t_data mlx_data, int x, int y)
{
	int				color;
	size_t			i;
	t_complex_nbr	z;
	t_complex_nbr	constant;

	constant.real = mlx_data.var_pos.x;
	constant.imag = mlx_data.var_pos.y;
	z.real = (mlx_data.boundary_x) + x / (WIN_SIZE / mlx_data.size);
	z.imag = (mlx_data.boundary_y) - y / (WIN_SIZE / mlx_data.size);
	color = 0x00000000;
	i = 0;
	while (i < mlx_data.precision && mlx_data.precision > 0)
	{
		absolute_power_complex(&z);
		z.real -= constant.real;
		z.imag -= constant.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
		{
			color = mlx_data.color.color_tab[mlx_data.color.color_select] * i;
			break ;
		}
		i++;
	}
	img_pix_put(&mlx_data.img, x, y, color);
}
