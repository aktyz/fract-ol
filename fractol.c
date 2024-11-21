/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:26:13 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 16:26:13 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_collect_julia_values(char *r, char *i, t_fractal *fractal);

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
			ft_collect_julia_values(argv[2], argv[3], &fractal);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_printf("Please enter\n./fractol mandelbrot\n");
		ft_printf("or\n./fractol julia <real> <i>\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

static void	ft_collect_julia_values(char *r, char *i, t_fractal *fractal)
{
	double	tmp;

	tmp = ft_fractol_atodbl(r);
	if (!tmp)
		exit(EXIT_FAILURE);
	else
	{
		fractal->julia_r = tmp;
		tmp = ft_fractol_atodbl(i);
		if (!tmp)
			exit(EXIT_FAILURE);
		else
			fractal->julia_i = tmp;
	}
}
