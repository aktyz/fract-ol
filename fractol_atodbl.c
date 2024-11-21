/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_atodbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:23:25 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/21 16:25:14 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(int c);
static void	ft_collect_integer(long *integer, char **c);
static void	ft_collect_fraction(double *fraction, double *pow, char **c);

double	ft_fractol_atodbl(char *s)
{
	long	integer;
	double	fraction;
	double	pow;
	int		sign;

	integer = 0;
	fraction = 0.0;
	pow = 1;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		ft_collect_integer(&integer, &s);
	if (*s == '.')
		s++;
	while (*s)
		ft_collect_fraction(&fraction, &pow, &s);
	return ((integer + fraction) * sign);
}

static int	ft_isspace(int c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	else
		return (0);
}

static void	ft_collect_integer(long *integer, char **c)
{
	if (ft_isdigit(**c))
	{
		*integer = (*integer * 10) + (**c - 48);
		(*c)++;
	}
	else
	{
		ft_printf("You have provided a number which is not a double\n");
		ft_printf("Try again with correct numbers\n");
		exit(EXIT_FAILURE);
	}
}

static void	ft_collect_fraction(double *fraction, double *pow, char **c)
{
	if (ft_isdigit(**c))
	{
		*pow /= 10;
		*fraction = *fraction + (**c - 48) * (*pow);
		(*c)++;
	}
	else
	{
		ft_printf("You have provided a number which is not a double\n");
		ft_printf("Try again with correct numbers\n");
		exit(EXIT_FAILURE);
	}
}
