/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:32:31 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 22:42:59 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(t_data mlx_data, int x, int y)
{
	int				color;
	size_t			i;
	t_complex_nbr	z;
	t_complex_nbr	constant;

	constant.real = mlx_data.var_pos.x;
	constant.imag = mlx_data.var_pos.y;
	z.real = mlx_data.boundary_x + x / (WIN_SIZE / mlx_data.size);
	z.imag = mlx_data.boundary_y - y / (WIN_SIZE / mlx_data.size);
	color = 0x0000000;
	i = 0;
	while (i < mlx_data.precision && mlx_data.precision > 0)
	{
		power_complex(&z);
		z.real += constant.real;
		z.imag += constant.imag;
		if (sqrt(pow(z.real, 2) + pow(z.imag, 2)) > 2)
		{
			color = mlx_data.color.color_tab[mlx_data.color.color_select] * i;
			break ;
		}
		i++;
	}
	img_pix_put(&mlx_data.img, x, y, color);
}
