/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:15:40 by seryilma          #+#    #+#             */
/*   Updated: 2023/02/06 22:19:26 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_fractal *my_fractal)
{
	my_fractal->my_img.img = mlx_new_image(my_fractal->mlx, WIDTH, HEIGHT);
	my_fractal->my_img.addr = mlx_get_data_addr(my_fractal->my_img.img,
			&my_fractal->my_img.bits_per_pixel, &my_fractal->my_img.line_length,
			&my_fractal->my_img.endian);
}

void	navigate_on_screen(t_fractal *my_fractal)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			convert_to_xy(my_fractal, i, j);
		}
	}
	mlx_put_image_to_window(my_fractal->mlx,
		my_fractal->win, my_fractal->my_img.img, 0, 0);
}

void	convert_to_xy(t_fractal *my_fractal, int i, int j)
{
	int		colour;
	int		w_division;
	int		h_division;
	float	initial_x;
	float	initial_y;

	w_division = WIDTH_DIVISION;
	h_division = HEIGHT_DIVISION;
	initial_x = (float)i / (float)w_division * my_fractal->zoom_rate;
	initial_y = (float)j / (float)h_division * my_fractal->zoom_rate;
	initial_x -= 5 + my_fractal->move_x;
	initial_y = (3 - my_fractal->move_y) - initial_y;
	if (my_fractal->name == 'm')
		colour = mandelbrot_formula(my_fractal, initial_x, initial_y);
	else if (my_fractal->name == 'j')
		colour = julia_formula(my_fractal, initial_x, initial_y);
	if (j < HEIGHT && i < WIDTH)
		my_mlx_pixel_put(&my_fractal->my_img, i, j, colour);
}
