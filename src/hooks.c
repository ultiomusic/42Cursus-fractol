/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:26:42 by beeligul          #+#    #+#             */
/*   Updated: 2023/07/28 16:04:08 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_hook(int keycode, t_fractal *my_fractal)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_A)
		my_fractal->move_x += 0.5 * my_fractal->zoom_rate;
	else if (keycode == KEY_D)
		my_fractal->move_x -= 0.5 * my_fractal->zoom_rate;
	else if (keycode == KEY_W)
		my_fractal->move_y -= 0.5 * my_fractal->zoom_rate;
	else if (keycode == KEY_S)
		my_fractal->move_y += 0.5 * my_fractal->zoom_rate;
	navigate_on_screen(my_fractal);
	return (1);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *my_fractal)
{
	int	mouse_x;
	int	mouse_y;

	mouse_x = WIDTH / 2 - x;
	mouse_y = HEIGHT / 2 - y;
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		if (keycode == SCROLL_UP)
			my_fractal->zoom_rate *= ZOOM_FACTOR;
		else
			my_fractal->zoom_rate /= ZOOM_FACTOR;
		my_fractal->move_x += 0.5 * my_fractal->zoom_rate * (double)mouse_x
			/ (double)(WIDTH / 2);
		my_fractal->move_y += 0.5 * my_fractal->zoom_rate * (double)mouse_y 
			/ (double)(HEIGHT / 2);
		navigate_on_screen(my_fractal);
	}
	if (keycode == LEFT_CLICK)
	{
		change_color_palette(my_fractal);
	}
	return (1);
}

int	click_x(void *param)
{
	(void)param;
	exit(0);
}

void	change_color_palette(t_fractal *my_fractal)
{
	static int	palette_set_number = 0;

	if (palette_set_number % 8 == 0)
		my_fractal->color_set = 123123;
	else if (palette_set_number % 8 == 1)
		my_fractal->color_set = 29000;
	else if (palette_set_number % 8 == 2)
		my_fractal->color_set = 602000;
	else if (palette_set_number % 8 == 3)
		my_fractal->color_set = 1120000;
	else if (palette_set_number % 8 == 4)
		my_fractal->color_set = 420000;
	else if (palette_set_number % 8 == 5)
		my_fractal->color_set = 965000;
	else if (palette_set_number % 8 == 6)
		my_fractal->color_set = 1320000;
	else if (palette_set_number % 8 == 7)
		my_fractal->color_set = 756321;
	palette_set_number++;
}
