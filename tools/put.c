/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:07:00 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/18 18:07:49 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fmlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	fmlx_pixel_put(data, x * 2, y * 2, color);
	fmlx_pixel_put(data, x * 2 + 1, y * 2, color);
	fmlx_pixel_put(data, x * 2, y * 2 + 1, color);
	fmlx_pixel_put(data, x * 2 + 1, y * 2 + 1, color);
}

int	color(int r, int g, int b)
{
	int	rgb;

	b = b % 512;
	if (b > 255)
		b = 255 - b % 256;
	r = r % 512;
	if (r > 255)
		r = 255 - r % 256;
	g = g % 512;
	if (g > 255)
		g = 255 - g % 256;
	rgb = ((r % 256) * 256 * 256) + ((g % 256) * 256) + (b % 256);
	return (rgb);
}

void	ft_color_put(int x, int y, t_vars vars, t_data img)
{
	double	smooth;

	smooth = vars.fractal(x, y, vars.display);
	if (smooth > vars.display.maxiter - 1)
		my_mlx_pixel_put(&img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(&img, x, y, color(21 * smooth
				+ vars.display.shift, 10 * smooth + vars.display.shift,
				50 * cos(smooth) + 130 + vars.display.shift));
}

int	ft_new_image(t_vars vars)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(vars.mlx, WIDTH * 2, HEIGHT * 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ft_color_put(x, y, vars, img);
			y++;
		}
		x++;
	}
	mlx_clear_window(vars.mlx, vars.win);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	return (0);
}
