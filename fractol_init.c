/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:28:01 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 16:28:01 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractal_init(t_fractal *fractal);
static void	ft_malloc_error(void);
void		data_init(t_fractal *fractal);

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		ft_malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
		WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
		WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_malloc_error();
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr,
		&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	//events_init(fractal);
	data_init(fractal);
}

void		data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->check_i = 42;
}

/**
 * Function handling failure to allocate mlx structures
 *
 */
static void	ft_malloc_error(void)
{
	ft_printf("\nProblems with mlx variables initialization!\n");
	exit(EXIT_FAILURE);
}
