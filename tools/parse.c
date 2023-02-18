/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:07:11 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/18 18:31:33 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_builtin	*ft_builtin(void)
{
	static t_builtin	builtin[7] = {
	{"mandelbrot1", &mandelbrot1},
	{"mandelbrot2", &mandelbrot2},
	{"mandelbrot3", &mandelbrot3},
	{"mandelbrot4", &mandelbrot4},
	{"julia", &julia},
	{"burning_ship", &ship},
	{NULL, NULL}
	};

	return (builtin);
}

void	*ft_fractal_choose(char *args)
{
	t_builtin	*search;
	int			i;

	search = ft_builtin();
	i = 0;
	while (search[i].str)
	{
		if (!ft_strcmp(args, search[i].str))
			return (search[i].f);
		i++;
	}
	return (NULL);
}

int	ft_error(void)
{
	write(2, "Wrong arg, valid arguments are:\n'mandelbrot[1-4]'\n'julia'\n", 58);
	write(2, "'burning_ship'\n", 15);
	exit (1);
}
