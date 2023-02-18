/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:48:32 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/09 20:48:33 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ship(double x, double y, t_display display)
{
	int		i;
	double	utils;
	t_dot	tmp;
	t_dot	res;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = fabs(res.x);
		res.x = x + fabs(tmp.x) - fabs(tmp.y);
		res.y = y + (fabs(utils) + fabs(utils)) * fabs(res.y);
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}
