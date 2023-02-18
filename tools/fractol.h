/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:06:22 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/18 18:07:22 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 960
# define HEIGHT 522

typedef struct s_display	t_display;
typedef struct s_ret		t_ret;
typedef struct s_dot		t_dot;

struct s_dot {
	double	x;
	double	y;
};

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

struct s_display {
	double				angle;
	double				offset_x;
	double				offset_y;
	double				julia_x;
	double				julia_y;
	long unsigned int	zoom;
	int					maxiter;
	int					shift;
};

typedef struct s_vars {
	void		*mlx;
	void		*win;
	double		(*fractal)(double, double, t_display);
	t_display	display;
}				t_vars;

typedef struct s_builtin {
	char	*str;
	double	(*f)(double, double, t_display);
}			t_builtin;

int			ft_new_image(t_vars vars);
int			colors(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			color(int r, int g, int b);
double		ship(double x, double y, t_display display);
double		gabi(double x, double y, t_display display);
double		mandelbrot1(double x, double y, t_display display);
double		mandelbrot2(double x, double y, t_display display);
double		mandelbrot3(double x, double y, t_display display);
double		mandelbrot4(double x, double y, t_display display);
double		julia(double x, double y, t_display display);
int			ft_close(int keycode, t_vars *vars);
int			ft_cross(t_vars *vars);
int			ft_new_image(t_vars vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int button, int x, int y, t_vars *vars);
t_builtin	*ft_builtin(void);
int			ft_strcmp(char *s1, char *s2);
void		*ft_fractal_choose(char *str);
int			ft_error(void);
double		ft_atod(const char *str);
void		ft_rotation(double *x, double *y, t_display display);

#endif
