/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:55:39 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/14 21:10:01 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	dot_convert(const char *str, int i, double neg)
{
	double	res;
	double	power;

	res = 0.0;
	power = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i++] - '0');
		power *= 10.0;
	}
	return (res * neg / power);
}

double	ft_atod(const char *str)
{
	int		i;
	double	neg;
	double	v;
	double	res;

	i = 0;
	neg = 1.0;
	v = 0.0;
	res = 0.0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		neg = -1.0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		v = v * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		res = v + dot_convert(str, ++i, neg);
	else
		res = v * neg;
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	colors(t_vars *vars)
{
	vars->display.shift += 1;
	ft_new_image(*vars);
	return (0);
}

void	ft_rotation(double *x, double *y, t_display display)
{
	double	utils;

	*x = ((*x - (WIDTH / 2)) / display.zoom + display.offset_x);
	*y = ((*y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	utils = *x;
	*x = *x * cos(0.01 * display.angle) - *y * sin(0.01 * display.angle);
	*y = *y * cos(0.01 * display.angle) + utils * sin(0.01 * display.angle);
}
