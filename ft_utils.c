/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:56:34 by seryilma          #+#    #+#             */
/*   Updated: 2023/02/06 22:24:06 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	argcheck(int ac, char **av, t_fractal *my_fractal)
{
	if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
	{
		my_fractal->name = 'j';
		if (check_arg_is_float(av[2]) == 1 && check_arg_is_float(av[3]) == 1)
		{
			my_fractal->j_x = ft_atof(av[2]);
			my_fractal->j_y = ft_atof(av[3]);
			return (1);
		}
		return (0);
	}
	else if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
	{
		my_fractal->name = 'm';
		return (1);
	}
	return (0);
}

int	charcompare(char arg, char referance)
{
	if (arg == referance)
		return (1);
	else if ('A' <= arg && arg <= 'Z' && arg + ('a' - 'A') == referance)
		return (1);
	return (0);
}

int	ft_strcmp(char *arg, char *ref)
{
	int	i;

	i = 0;
	while (charcompare(arg[i], ref[i]) && arg[i] != '\0' && ref[i] != '\0')
		i++;
	return (arg[i] - ref[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
