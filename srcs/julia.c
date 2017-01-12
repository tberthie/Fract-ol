/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:32:59 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/12 15:52:06 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <mlx.h>
#include <math.h>

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

static int		color(long double i)
{
	if (i <= 0.16)
		return (((int)(32 * i / 0.16) << 16) + ((int)(7 + 100 * i /
		0.16) << 8) + (100 + 103 * i / 0.16));
	else if (i <= 0.42 && (i -= 0.16))
		return (((int)(32 + 205 * i / 0.26) << 16) + ((int)(107 + 148 * i /
		0.26) << 8) + (203 + 42 * i / 0.26));
	else if (i <= 0.6425 && (i -= 0.42))
		return (((int)(237 + 18 * i / 0.2225) << 16) + ((int)(255 - 85 * i /
		0.2225) << 8) + (255 - 255 * i / 0.2225));
	else if (i <= 0.8575 && (i -= 0.6425))
		return (((int)(255 - 255 * i / 0.215) << 16) + ((int)(170 - 168 * i /
		0.215) << 8));
	else
		return ((int)(2 - 2 * (i -= 0.8575) / 0.1425) << 8);
}

static int		pixel(t_fract *fract, long double x, long double y)
{
	long double		i;
	long double		zoom;

	zoom = 1 / fract->zoom;
	x = 2 * (2 * (x - (WINX / 2)) / WINX) * zoom;
	y = 2 * (y - (WINY / 2)) / WINY * zoom;
	i = iter(fract, x, y);
	return (i != fract->iter) ? color(i / fract->iter) : 0;
}

void			julia(t_fract *fract)
{
	void			*img;
	char			*pixs;
	unsigned int	color;
	int				i;

	img = mlx_new_image(fract->mlx, WINX, WINY);
	pixs = mlx_get_data_addr(img, &(fract->bpp), &(fract->ls), &(fract->end));
	i = 0;
	while (i < WINX * WINY)
	{
		color = mlx_get_color_value(fract->mlx,
		pixel(fract, i % WINX + fract->x, i / WINX + fract->y));
		pixs[0] = color;
		pixs[1] = color >> 8;
		pixs[2] = color >> 16;
		pixs += 4;
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, img, 0, 0);
}
