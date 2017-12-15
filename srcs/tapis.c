/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:11 by tberthie          #+#    #+#             */
/*   Updated: 2017/12/15 18:52:13 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				tapis(t_fract *fract, long double x, long double y)
{
	long double zoom;
	int			rx;
	int			ry;

	zoom = 1 / fract->zoom;
	rx = WINX * (2 * (x - (WINX / 2)) / WINX) * zoom;
	rx = rx + (rx < 0) * -rx * 2;
	ry = WINY * (2 * (y - (WINY / 2)) / WINY) * zoom;
	ry = ry + (ry < 0) * -ry * 2;
	while (rx > 0 || ry > 0)
	{
		if (rx % 3 == 1 && ry % 3 == 1)
			return (0x2050a0);
		rx /= 3;
		ry /= 3;
	}
	return (0);
}
