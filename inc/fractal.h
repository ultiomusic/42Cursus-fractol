/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:27:10 by beeligul          #+#    #+#             */
/*   Updated: 2023/07/10 18:06:56 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "keys.h"

# define WIDTH 1080
# define HEIGHT 720
# define WIDTH_DIVISION 120
# define HEIGHT_DIVISION 120
# define ITER 150
# define ZOOM_FACTOR 0.9

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	char			name;
	void			*mlx;
	void			*win;
	struct s_data	my_img;
	struct s_data	my_blackimg;
	float			zoom_rate;
	float			move_x;
	float			move_y;
	float			j_x;
	float			j_y;
	int				color_set;
}	t_fractal;

int		argcheck(int ac, char **av, t_fractal *my_fractal);
int		charcompare(char arg, char referance);
int		ft_strcmp(char *arg, char *ref);
int		ft_strlen(char *str);

int		check_arg_is_float(char *arg);
int		ft_atoi(const char *str);
float	ft_atof(char *str);
void	init_window(t_fractal *my_fractal);

int		key_hook(int keycode, t_fractal *my_fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *my_fractal);
int		click_x(void *param);
void	change_color_palette(t_fractal *my_fractal);

int		mandelbrot_formula(t_fractal *frac, float init_x, float init_y);
int		julia_formula(t_fractal *my_fractal, float initial_x, float initial_y);

void	create_image(t_fractal *my_fractal);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	convert_to_xy(t_fractal *my_fractal, int i, int j);
void	navigate_on_screen(t_fractal *my_fractal);

#endif
