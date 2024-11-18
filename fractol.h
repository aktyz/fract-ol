/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:21:13 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 16:21:13 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h> // malloc free exit
#include <math.h>
#include "libft/headers/libft.h"
#include "minilibx-linux/mlx.h"

#define	ERROR_MESSAGE "Please enter\n./fractol mandelbrot\nor\n./fractol julia <x> <y>\n"
#define	WIDTH 800
#define	HEIGHT 800

// Basic colors
#define	BLACK	0x000000 // Black
#define	WHITE	0xFFFFFF // White

// Psychedelic colors
#define NEON_GREEN    0x39FF14 // Bright neon green
#define HOT_PINK      0xFF1493 // Hot pink
#define ELECTRIC_BLUE 0x2C75FF // Vibrant electric blue
#define LIME_YELLOW   0xCCFF00 // Lime yellow
#define FIERY_RED     0xFF2400 // Fiery red
#define ORANGE_PEEL   0xFFA500 // Psychedelic orange
#define ULTRA_VIOLET  0x800080 // Deep ultraviolet purple
#define CYAN_SPARKLE  0x00FFFF // Cyan sparkle
#define MAGENTA_RUSH  0xFF00FF // Vivid magenta

/**
 * Structure used as a pixel buffer
 *
 */
typedef struct s_img
{
	void	*img_ptr; // pointer to image struct
	char	*pix_ptr;
	int		bpp; // bits per pixel
	int		endian;
	int		line_len;
}	t_img;

/**
 * Structure containing all the necessary data to draw a fractal
 * in my application
 * ~ MLX wiring
 * ~ Image structure
 * ~ Hooks values
 */
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		check_i;
}	t_fractal;

/**
 * Structure containing complex numbers with:
 * r - standing for real component
 * i - standing for imaginary component
 *
 */
typedef struct s_cmplx
{
	double	r;
	double	i;
}	t_cmplx;

/**
 * Program functions
 *
 */
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	ft_scale(double nb, double new_min, double new_max,
	double old_min, double old_max);
t_cmplx	sum_complex(t_cmplx x, t_cmplx y);
t_cmplx	square_complex(t_cmplx c);

#endif
