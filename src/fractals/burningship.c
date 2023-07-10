/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:48 by beeligul          #+#    #+#             */
/*   Updated: 2023/07/10 19:23:49 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int burningship_formula(t_fractal *frac, float init_x, float init_y)
{
    float zx = 0;
    float zy = 0;
    float temp;
    int count = 0;

    while (zx * zx + zy * zy <= 4 && count < ITER)
    {
        temp = zx * zx - zy * zy + init_x;
        zy = fabs(2 * zx * zy) + init_y;
        zx = fabs(temp);
        count++;
    }

    if (count == ITER)
        return 0;

    double zn = zx * zx + zy * zy;
    double log_zn = log(zn);
    double nu = log(log_zn / log(2)) / log(2);
    count = count + 1 - nu;

    return ((count * frac->color_set) % 16777215);
}