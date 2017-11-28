/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:11 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/25 15:53:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iter(t_fract *fract, long double x, long double y)
{
	long double	zr;
	long double	zi;
	long double	tmp;
	int			i;

	i = 0;
	zr = 0;
	zi = 0;
	while (zr + zi <= 2 && i < fract->iter)
	{
		tmp = 2 * (fabsl(zr) * fabsl(zi)) + y;
		zr = zr * zr - zi * zi + x;
		zi = tmp;
		i++;
	}
	return (i);
}

int				ship(t_fract *fract, long double x, long double y)
{
	long double		i;
	long double		zoom;

	zoom = 1 / fract->zoom;
	x = 2 * (2 * (x - (WINX / 2)) / WINX) * zoom;
	y = (2 * (y - (WINY / 2)) / WINY) * zoom;
	i = iter(fract, x, y);
	return (i != fract->iter) ? color(i / fract->iter) : 0;
}
