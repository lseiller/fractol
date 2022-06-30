/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:27:56 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 23:05:37 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE 500
# define _END "\e[0m"
# define _BOLD "\e[1m"
# define _GREY "\e[30m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"
# define _BLUE "\e[34m"

# include "../../libft/includes/libft.h"
# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"
# include <stddef.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_complex_number
{
	double	real;
	double	imag;
}	t_complex_nbr;

typedef struct s_variable_constant_pos
{
	double	x;
	double	y;
	char	boolean;
}	t_variable_constant_pos;
typedef struct s_img_mlx
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img_mlx;

typedef struct s_color
{
	int	color_tab[7];
	int	color_select;
}	t_color;

typedef struct s_data_mlx
{
	size_t					precision;
	void					*mlx_ptr;
	void					*win_ptr;
	void					(*funct)();
	double					size;
	double					boundary_x;
	double					boundary_y;
	double					intensity;
	t_img_mlx				img;
	t_color					color;
	t_variable_constant_pos	var_pos;
}	t_data;

//hook_handler.c
int		handle_no_event(void *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		handle_destroy(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);

//mlx_tools.c
void	mlx_init_data(t_data *mlx_data);
void	img_pix_put(t_img_mlx *mlx_img, int x, int y, int color);

//hook_tools.c
void	setting_up_hook(t_data mlx_data);
void	moving_the_view(int keysym, t_data *mlx_data);
void	hook_with_refresh(int keysym, t_data *mlx_data);
void	change_value_from_mouse_position(t_data *mlx_data);

//mandelbrot.c
void	mandelbrot_set(t_data mlx_data, int x, int y);
//julia.c
void	julia_set(t_data mlx_data, int x, int y);
//burning_ship.c
void	burning_ship_set(t_data mlx_data, int x, int y);
void	burning_julia_set(t_data mlx_data, int x, int y);

//math_tools.c
void	power_complex(t_complex_nbr *z);
void	absolute_power_complex(t_complex_nbr *z);

//main.c
void	exec_equation(t_data mlx_data);

#endif
