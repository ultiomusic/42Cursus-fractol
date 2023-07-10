/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:26:13 by beeligul          #+#    #+#             */
/*   Updated: 2023/07/10 17:26:14 by beeligul         ###   ########.fr       */
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
