/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:35:37 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/15 15:18:56 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot1(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = 0;
	return (utils);
}

double	mandelbrot2(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	return (utils);
}

double	mandelbrot3(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}

double	mandelbrot4(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	ft_rotation(&x, &y, display);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}
