/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:59:06 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/22 16:12:10 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Init mlx connexion to x_server, create mlx_windows, create mlx_image,
//retrieve mlx_image information
void	mlx_init_data(t_data *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		exit (1);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, WIN_SIZE, WIN_SIZE,
			"KIDS, DO DRUG");
	if (!mlx_data->win_ptr)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		exit (2);
	}
	mlx_data->img.mlx_img = mlx_new_image(mlx_data->mlx_ptr,
			WIN_SIZE, WIN_SIZE);
	if (!mlx_data->img.mlx_img)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		exit (3);
	}
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.mlx_img,
			&mlx_data->img.bpp, &mlx_data->img.line_len, &mlx_data->img.endian);
}

void	img_pix_put(t_img_mlx *mlx_img, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)(mlx_img->addr + (mlx_img->line_len * y + x
				* (mlx_img->bpp / 8)));
	*pixel = color;
}
