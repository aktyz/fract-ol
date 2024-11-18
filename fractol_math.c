/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:50:53 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/18 17:50:53 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmplx	sum_complex(t_cmplx x, t_cmplx y);
t_cmplx	square_complex(t_cmplx c);

/**
 * Function that will vector add x and y complex numbers.
 *
 */
t_cmplx	sum_complex(t_cmplx x, t_cmplx y)
{
	t_cmplx	result;

	result.r = x.r + y.r;
	result.i = x.i + y.i;
	return (result);
}

/**
 * Function implementing the formula for squarying a complex number:
 * real = (r^2 - i^2)
 * img = 2 * r * i
 * (using the same notation as in my t_cmplx structure)
 *
 */
t_cmplx	square_complex(t_cmplx z)
{
	t_cmplx	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = 2 * z.r * z.i;
	return (result);
}
