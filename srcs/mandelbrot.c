/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:11 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/10 17:54:15 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <mlx.h>

int			pixel(t_fract *fract, long double x, long double y)
{
	long double	i;
	long double xr;
	long double yr;
	long double	zr;
	long double	zi;
	long double	tmp;

	xr = (-2 + 3 * (x / WINX));
	yr =  (-1 + 2 * (y / WINY));
	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi < 4 && i < fract->iter)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + xr;
		zi = 2 * tmp * zi + yr;
		i++;
	}
	return (i != fract->iter) ? i / fract->iter * 255 : 0;
}

void		mandelbrot(t_fract *fract)
{
	void			*img;
	char			*pixs;
	unsigned int	color;
	int				i;

	int		a = 32;
	int		b = WINX * 4;
	int		c = 0;

	img = mlx_new_image(fract->mlx, WINX, WINY);
	pixs = mlx_get_data_addr(img, &a, &b, &c);
	i = 0;
	while (i < WINY * WINX * 4)
	{
		color = mlx_get_color_value(fract->mlx,
		pixel(fract, i / 4 % WINX, i / 4 / WINX));
		pixs[i] = color >> 16;
		pixs[i + 1] = color >> 8;
		pixs[i + 2] = color;
		i += 4;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, img, 0, 0);
}
