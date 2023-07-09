/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:44:53 by seryilma          #+#    #+#             */
/*   Updated: 2023/02/06 22:24:57 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot_formula(t_fractal *frac, float init_x, float init_y)
{
	float	imagine;
	float	reel;
	float	hold_reel;
	int		count;

	imagine = 0;
	reel = 0;
	count = 0;
	while (imagine * imagine + reel * reel <= 4 && count < ITER)
	{
		hold_reel = reel;
		reel = (reel * reel - imagine * imagine) + init_x;
		imagine = (2 * imagine * hold_reel) + init_y;
		count++;
	}
	return ((count * frac->color_set) % 16777215);
}
