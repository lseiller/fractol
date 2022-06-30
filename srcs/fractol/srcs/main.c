/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:27:13 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/30 11:17:38 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initialization of default value
static void	init_value(t_data *mlx_data)
{
	mlx_init_data(mlx_data);
	mlx_data->size = 4.0;
	mlx_data->boundary_x = -2;
	mlx_data->boundary_y = 2;
	mlx_data->precision = 5;
	mlx_data->intensity = 0.1;
	mlx_data->var_pos.boolean = 0;
	mlx_data->color.color_select = 0;
	mlx_data->color.color_tab[0] = 0x0009250e;
	mlx_data->color.color_tab[1] = 0x00050505;
	mlx_data->color.color_tab[2] = 0x00101010;
	mlx_data->color.color_tab[3] = 0x00070712;
	mlx_data->color.color_tab[4] = 0x009925be;
	mlx_data->color.color_tab[5] = 0x00120202;
	mlx_data->color.color_tab[6] = 0x3fa31d5a;
}

static void	init_variable_const(t_data *mlx_data, int argc, char **argv)
{
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		mlx_data->funct = &mandelbrot_set;
	else if (!ft_strcmp(argv[1], "BurningShip"))
		mlx_data->funct = &burning_ship_set;
	else if (!ft_strcmp(argv[1], "Julia"))
		mlx_data->funct = &julia_set;
	else if (!ft_strcmp(argv[1], "BurningJulia"))
		mlx_data->funct = &burning_julia_set;
	if (argc == 4)
	{
		mlx_data->var_pos.x = ft_atof(argv[2]);
		mlx_data->var_pos.y = ft_atof(argv[3]);
	}
	else
	{
		mlx_data->var_pos.x = 0;
		mlx_data->var_pos.y = 0;
	}
}

void	exec_equation(t_data mlx_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			mlx_data.funct(mlx_data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.win_ptr,
		mlx_data.img.mlx_img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	mlx_data;

	if (!ft_strcmp(argv[1], "Mandelbrot") || !ft_strcmp(argv[1], "Julia")
		|| !ft_strcmp(argv[1], "BurningJulia")
		|| !ft_strcmp(argv[1], "BurningShip"))
		init_variable_const(&mlx_data, argc, argv);
	else
	{
		ft_putstr_fd(_BOLD _BLUE "Usage: fractol [NAME]\n" _END _GREY "Render "
			"FRACTAL to standard X server windows\n\nName of Fractal :\n" _GREEN
			"Mandelbrot\tThe most famous fractal\nJulia\t\tVariable constant\t"
			"\tYou can set two float after Julia to set a constant\nBurningShip"
			"\tLook like a burning ship\nBurningJulia\tBurningShip and Julia\t"
			"\tYou can set two float after Julia to set a constant\n"
			_END, 1);
		exit(0);
	}
	init_value(&mlx_data);
	exec_equation(mlx_data);
	setting_up_hook(mlx_data);
	mlx_destroy_display(mlx_data.mlx_ptr);
	free(mlx_data.mlx_ptr);
	return (0);
}
