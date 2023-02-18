/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:07:18 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/18 18:07:22 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_cross(t_vars *vars)
{
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}

double	mouse_scroll(int button, int x, int y, t_vars *vars)
{
	double	zoom;

	zoom = vars->display.zoom;
	if (button == 5)
	{
		zoom = zoom * 1 / 1.5;
		vars->display.maxiter *= 1.0 / 1.02;
		vars->display.shift -= 20;
		vars->display.offset_x -= 0.15 * (((double)x - (WIDTH)) / zoom);
		vars->display.offset_y -= 0.15 * (((double)y - (HEIGHT)) / zoom);
	}
	else if (button == 4)
	{
		zoom = zoom * 1.5;
		vars->display.maxiter *= 1.03;
		vars->display.shift += 20;
		vars->display.offset_x += 0.3 * (((double)x - (WIDTH)) / zoom);
		vars->display.offset_y += 0.3 * (((double)y - (HEIGHT)) / zoom);
	}
	return (zoom);
}

double	mouse_clicks(int button, int x, int y, t_vars *vars)
{
	double	zoom;

	zoom = vars->display.zoom;
	if (button == 1)
	{
		zoom *= 1.5;
		vars->display.shift += 10;
		vars->display.maxiter *= 1.03;
		vars->display.offset_x += 0.5 * (((double)x - (WIDTH)) / zoom);
		vars->display.offset_y += 0.5 * (((double)y - (HEIGHT)) / zoom);
	}
	else if (button == 3)
	{
		zoom *= 1 / 1.5;
		vars->display.shift -= 10;
		vars->display.maxiter *= 1 / 1.02;
		vars->display.offset_x -= 0.3 * (((double)x - (WIDTH)) / zoom);
		vars->display.offset_y -= 0.3 * (((double)y - (HEIGHT)) / zoom);
	}
	return (zoom);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	zoom;

	zoom = vars->display.zoom;
	if (button == 1 || button == 3)
		zoom = mouse_clicks(button, x, y, vars);
	else if (button == 4 || button == 5)
		zoom = mouse_scroll(button, x, y, vars);
	else if (button == 2)
	{
		vars->display.julia_x = (((double)x - (WIDTH)) / zoom);
		vars->display.julia_y = (((double)y - (HEIGHT)) / zoom);
	}
	if (zoom <= 10)
		zoom = 15;
	else if (zoom >= 16288724607337290)
		zoom = 16288724607337290;
	vars->display.zoom = zoom;
	ft_new_image(*vars);
	return (0);
}
