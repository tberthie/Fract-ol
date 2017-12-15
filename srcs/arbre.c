/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:36:11 by tberthie          #+#    #+#             */
/*   Updated: 2017/12/15 19:40:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_len(int *coords)
{
	int		diff[2];

	diff[0] = coords[2] - coords[0];
	diff[1] = coords[3] - coords[1];
	return (sqrt(pow(diff[0], 2) + pow(diff[1], 2)));
}

static void		draw_line(t_fract *fract, int *coords, int iter)
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
	while (i <= len)
	{
		ratio = (float)i / len;
		pos = (coords[0] + WINX * coords[1] + (int)(diff[0] * ratio) +
		(int)(diff[1] * ratio) * WINX) * 4;
		fract->pixs[pos + 1] = 75 + 75 * (iter <= 4);
		fract->pixs[pos + 2] = 150 - 100 * (iter <= 4);
		i++;
	}
}

static void		branch(t_fract *fract, int *coords, int angle, int iter)
{
	int		len;
	int		*coords2;
	int		*coords3;

	if ((len = (get_len(coords) * 0.9)) >= 1)
	{
		coords2 = ft_m(16);
		coords3 = ft_m(16);
		coords2[0] = coords[2];
		coords2[1] = coords[3];
		coords2[2] = coords2[0] + len * cos(angle * M_PI / 180);
		coords2[3] = coords2[1] + len * sin(angle * M_PI / 180);
		ft_memcpy(coords3, coords2, 16);
		draw_line(fract, coords2, iter);
		if (--iter)
		{
			branch(fract, coords2, angle + 15 * fract->zr, iter);
			branch(fract, coords3, angle - 15 * fract->zi, iter);
		}
		free(coords2);
		free(coords3);
	}
}

void			arbre(t_fract *fract)
{
	int			iter;
	int			*coords;
	int			*coords2;

	fract->iter = fract->iter > 180 ? 180 : fract->iter;
	coords = ft_m(16);
	coords2 = ft_m(16);
	iter = fract->iter / 10;
	ft_memset(fract->pixs, 4 * WINX * WINY, 0);
	coords[0] = WINX / 2;
	coords[1] = WINY - 1;
	coords[2] = coords[0];
	coords[3] = coords[1] - 100;
	ft_memcpy(coords2, coords, 16);
	draw_line(fract, coords, 5);
	if (--iter)
	{
		branch(fract, coords, -75, iter);
		branch(fract, coords2, -105, iter);
	}
	free(coords);
	free(coords2);
}
