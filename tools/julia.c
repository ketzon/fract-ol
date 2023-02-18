/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:06:33 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/18 18:06:35 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	julia(double x, double y, t_display display)
{
	int		i;
	t_dot	tmp;
	t_dot	res;
	double	utils;

	res.x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	res.y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	tmp.x = res.x * res.x;
	tmp.y = res.y * res.y;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < display.maxiter * 50)
	{
		utils = res.x;
		res.x = display.julia_x + tmp.x - tmp.y ;
		res.y = display.julia_y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}
