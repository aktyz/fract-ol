/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:12:09 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 22:12:09 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	button_handler(int button, int x, int y, t_fractal *fractal);
int	close_handler(t_fractal *fractal);
//int	julia_track(int x, int y, t_fractal *fractal);
int	key_handler(int keysym, t_fractal *fractal);

int	button_handler(int button, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (button == 4)
		fractal->zoom *= 0.95;
	if (button == 5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_period)
		fractal->check_i += 10;
	else if (keysym == XK_comma)
		fractal->check_i -= 10;
	fractal_render(fractal);
	return (0);
}

/*int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_r = ft_scale(x, -2, 2, WIDTH)
			* fractal->zoom + fractal->shift_x;
		fractal->julia_i = ft_scale(y, 2, -2, HEIGHT)
			* fractal->zoom + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}*/