/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:06:33 by seryilma          #+#    #+#             */
/*   Updated: 2023/02/06 22:11:55 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_arg_is_float(char *arg)
{
	int	i;
	int	dot_flag;

	i = 0;
	dot_flag = 0;
	while (arg[i] && ft_strlen(arg) < 9)
	{
		if (arg[i] == '.')
		{
			if (dot_flag == 1)
				return (0);
			else
				dot_flag = 1;
		}
		else if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	if (dot_flag == 0)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	nbr;
	int			is_minus;
	int			i;

	nbr = 0;
	i = 0;
	is_minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_minus = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
			;
		else
			nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * is_minus);
}

float	ft_atof(char *str)
{
	int		i;
	int		nbr;
	float	result;
	int		divider;

	i = 1;
	divider = (ft_strlen(str) - 2);
	nbr = ft_atoi(str);
	divider = pow(10, divider);
	result = (float)nbr / divider;
	return (result);
}
