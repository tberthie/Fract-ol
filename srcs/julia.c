/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:32:59 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/28 20:56:27 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iter(t_fract *fract, long double x, long double y)
{
	long double	zr;
	long double	zi;
	long double	zrsq;
	long double	zisq;
	int			i;

	i = 0;
	zr = x;
	zi = y;
	zrsq = zr * zr;
	zisq = zi * zi;
	while (zrsq + zisq <= 4 && i < fract->iter)
	{
		zi = (zr + zi) * (zr + zi) - zrsq - zisq + fract->zi;
		zr = zrsq - zisq + fract->zr;
		zrsq = zr * zr;
		zisq = zi * zi;
		i++;
	}
	return (i);
}

int				julia(t_fract *fract, long double x, long double y)
{
	long double		i;
	long double		zoom;

	zoom = 1 / fract->zoom;
	x = 2 * (2 * (x - (WINX / 2)) / WINX) * zoom;
	y = 2 * (y - (WINY / 2)) / WINY * zoom;
	i = iter(fract, x, y);
	return (i != fract->iter) ? color(i / fract->iter) : 0;
}
