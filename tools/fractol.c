/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:06:12 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/18 18:07:56 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	display_init(void)
{
	t_display	display;

	display.angle = 0;
	display.offset_x = 0;
	display.offset_y = 0;
	display.zoom = 200;
	display.maxiter = 40;
	display.shift = 0;
	display.julia_x = 0;
	display.julia_y = 0;
	return (display);
}

t_display	ft_julia_init(char *x, char *y)
{
	t_display	display;

	display.angle = 0;
	display.offset_x = 0;
	display.offset_y = 0;
	display.zoom = 200;
	display.maxiter = 40;
	display.shift = 0;
	display.julia_x = ft_atod(x);
	display.julia_y = ft_atod(y);
	return (display);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	vars.fractal = ft_fractal_choose(av[1]);
	if (!vars.fractal)
		ft_error();
	if (ac == 4 && !ft_strcmp("julia", av[1]))
		vars.display = ft_julia_init(av[2], av[3]);
	else if (ac != 2)
		ft_error();
	if (ac == 2)
		vars.display = display_init();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	mlx_do_key_autorepeatoff(vars.mlx);
	vars.win = mlx_new_window(vars.mlx, WIDTH * 2, HEIGHT * 2, "fbesson");
	if (!vars.win)
		return (0);
	mlx_loop_hook(vars.mlx, &colors, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_cross, &vars);
	mlx_hook(vars.win, 2, 1, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
