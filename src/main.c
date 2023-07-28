/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:26:47 by beeligul          #+#    #+#             */
/*   Updated: 2023/07/24 11:36:29 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_window(t_fractal *my_fractal)
{
	my_fractal->mlx = mlx_init();
	my_fractal->win = mlx_new_window(my_fractal->mlx,
			WIDTH, HEIGHT, "MY FRACTALS");
	create_image(my_fractal);
	change_color_palette(my_fractal);
	navigate_on_screen(my_fractal);
	mlx_mouse_hook(my_fractal->win, mouse_hook, my_fractal);
	mlx_key_hook(my_fractal->win, key_hook, my_fractal);
	mlx_hook(my_fractal->win, 17, 0, click_x, NULL);
	mlx_loop(my_fractal->mlx);
}

int	main(int ac, char **av)
{
	t_fractal	my_fractal;

	my_fractal.move_x = 0;
	my_fractal.move_y = 0;
	my_fractal.zoom_rate = 1;
	if (ac == 2 || ac == 4)
	{
		if (argcheck(ac, av, &my_fractal) == 1)
		{
			init_window(&my_fractal);
		}
		else
		{
			printf("Invalid Entry!");
			return (1);
		}
	}
	else
	{
		printf("Invalid Entry!");
		return (1);
	}
	return (0);
}
