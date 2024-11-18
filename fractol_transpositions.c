/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_transpositions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:22 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 17:31:22 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_scale(double nb, double new_min, double new_max,
	double old_min, double old_max);

double	ft_scale(double nb, double new_min, double new_max,
	double old_min, double old_max)
	{
		double	a;
		double	b;

		a = new_max - new_min;
		b = old_max - old_min;
		return ((a) * (nb - old_min) / (b) + new_min);
	}
