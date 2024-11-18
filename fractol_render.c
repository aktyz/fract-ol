/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:21:23 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 17:21:23 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractal_render(t_fractal *fractal);
static void	ft_handle_pixel(int x, int y, t_fractal *fractal);
static void	ft_pixel_put(int x, int y, t_img *img, int color);

/**
 * Function rendering Mandelbrod fractal.
 *
 */
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
/**
 * Function checks if imaginary point z = x + yi belongs to Mandelbrod set
 *
 * Theorem used:
 * -
 * - complex numbers calculus
 * - Pythagoram theorem
 */
static void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	t_cmplx	z;
	t_cmplx	c;
	int			i;
	int			color;

	z.r = 0.0;
	z.i = 0.0;
	c.r = ft_scale(x, -2, +2, 0, WIDTH);
	c.i = ft_scale(y, +2, -2, 0, HEIGHT);
	i = 0;

	while (i < fractal->check_i)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->escape_value)
		{
			color = ft_scale(i, BLACK, WHITE, 0, fractal->check_i);
			ft_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractal->img, CYAN_SPARKLE);
}

/**
 * Function defines the pixel in the pixel buffer
 *
 */
static void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}
