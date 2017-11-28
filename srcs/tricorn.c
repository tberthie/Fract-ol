/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:11 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/25 15:53:30 by tberthie         ###   ########.fr       */
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
	zr = 0;
	zi = 0;
	zrsq = 0;
	zisq = 0;
	while (zrsq + zisq <= 4 && i < fract->iter)
	{
		zi = (zr - zi) * (zr - zi) - zrsq - zisq + y;
		zr = zrsq - zisq + x;
		zrsq = zr * zr;
		zisq = zi * zi;
		i++;
	}
	return (i);
}

int				tricorn(t_fract *fract, long double x, long double y)
{
	long double		i;
	long double		zoom;

	zoom = 1 / fract->zoom;
	x = -0.75 + 1.75 * (2 * (x - (WINX / 2)) / WINX) * zoom;
	y = 1 * (2 * (y - (WINY / 2)) / WINY) * zoom;
	i = iter(fract, x, y);
	return (i != fract->iter) ? color(i / fract->iter) : 0;
}
