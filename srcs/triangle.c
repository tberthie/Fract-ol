/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:11 by tberthie          #+#    #+#             */
/*   Updated: 2017/12/15 19:46:51 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_line(t_fract *fract, int *coords)
{
	int		diff[2];
	int		len;
	int		i;
	float	ratio;
	int		pos;

	diff[0] = coords[2] - coords[0];
	diff[1] = coords[3] - coords[1];
	len = sqrt(pow(diff[0], 2) + pow(diff[1], 2)) + 1;
	i = 0;
	while (len >= 1 && i <= len)
	{
		ratio = (float)i / len;
		pos = (coords[0] + WINX * coords[1] + (int)(diff[0] * ratio) +
		(int)(diff[1] * ratio) * WINX) * 4;
		fract->pixs[pos + 2] = -127;
		i++;
	}
}

static void		draw_triangle(t_fract *fract, int *coords, int iter)
{
	int		*new;
	int		i;

	new = (int*)ft_memalloc(24);
	ft_memcpy(new, coords, 24);
	draw_line(fract, coords);
	draw_line(fract, coords + 2);
	ft_memcpy(coords + 2, coords + 4, 8);
	draw_line(fract, coords);
	i = 0;
	while (iter && i < 3)
	{
		ft_memcpy(coords, new, 24);
		coords[0] -= (i == 1) * ((new[4] - new[2]) / 4);
		coords[0] += (i == 2) * ((new[4] - new[2]) / 4);
		coords[1] += (i > 0) * ((new[3] - new[1]) / 2);
		coords[2] += (i == 0) * ((new[4] - new[2]) / 4);
		coords[3] -= (i == 0) * ((new[3] - new[1]) / 2);
		coords[4] -= (i == 0) * ((new[4] - new[2]) / 4);
		coords[5] -= (i == 0) * ((new[3] - new[1]) / 2);
		coords[4] -= (i == 1) * ((new[4] - new[2]) / 2);
		coords[2] += (i++ == 2) * ((new[4] - new[2]) / 2);
		draw_triangle(fract, coords, iter - 1);
	}
	free(new);
}

void			triangle(t_fract *fract)
{
	int			iter;
	int			*coords;

	fract->iter = fract->iter > 100 ? 100 : fract->iter;
	iter = fract->iter / 10;
	ft_memset(fract->pixs, 4 * WINX * WINY, 0);
	coords = (int*)ft_memalloc(24);
	coords[0] = WINX / 2;
	coords[1] = WINY / 2 - 300;
	coords[2] = WINX / 2 - 300;
	coords[3] = WINY / 2 + 300;
	coords[4] = WINX / 2 + 300;
	coords[5] = WINY / 2 + 300;
	if (iter)
		draw_triangle(fract, coords, iter - 1);
	free(coords);
}
