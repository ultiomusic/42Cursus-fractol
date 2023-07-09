/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:43:42 by seryilma          #+#    #+#             */
/*   Updated: 2023/02/06 21:44:32 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia_formula(t_fractal *my_fractal, float initial_x, float initial_y)
{
	float	imagine;
	float	reel;
	float	hold_reel;
	int		count;

	imagine = initial_x;
	reel = initial_y;
	count = 0;
	while (imagine * imagine + reel * reel <= 4 && count < ITER)
	{
		hold_reel = reel;
		reel = (reel * reel - imagine * imagine) - my_fractal->j_x;
		imagine = (2 * imagine * hold_reel) + my_fractal->j_y;
		count++;
	}
	return ((count * my_fractal->color_set) % 16777215);
}
