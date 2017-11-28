/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:29:10 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/28 18:05:34 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int		calculate_pixel(t_fract *fract, unsigned int i)
{
	unsigned int	color;

	if (fract->type == 'm')
		color = mlx_get_color_value(fract->mlx,
		mandelbrot(fract, i % WINX + fract->x, i / WINX + fract->y));
	if (fract->type == 'j')
		color = mlx_get_color_value(fract->mlx,
		julia(fract, i % WINX + fract->x, i / WINX + fract->y));
	if (fract->type == 'b')
		color = mlx_get_color_value(fract->mlx,
		bird(fract, i % WINX + fract->x, i / WINX + fract->y));
	if (fract->type == 's')
		color = mlx_get_color_value(fract->mlx,
		ship(fract, i % WINX + fract->x, i / WINX + fract->y));
	if (fract->type == 't')
		color = mlx_get_color_value(fract->mlx,
		tricorn(fract, i % WINX + fract->x, i / WINX + fract->y));
	if (fract->type == 'T')
		color = mlx_get_color_value(fract->mlx,
		tapis(fract, i % WINX + fract->x, i / WINX + fract->y));
	return (color);
}

static void				*calculate(void *arg)
{
	t_fract			*fract;
	unsigned int	color;
	unsigned int	i;
	unsigned int	size;

	fract = (t_fract*)arg;
	size = WINX * WINY / THREAD;
	i = size * fract->thread;
	fract->pixs += i * 4;
	while (i < size * fract->thread + size)
	{
		color = calculate_pixel(fract, i);
		fract->pixs[0] = color;
		fract->pixs[1] = color >> 8;
		fract->pixs[2] = color >> 16;
		fract->pixs += 4;
		i++;
	}
	return (0);
}

void					render(t_fract *fract)
{
	t_fract			*thread[THREAD];
	pthread_t		id[THREAD];
	int				i;

	fract->img = mlx_new_image(fract->mlx, WINX, WINY);
	fract->pixs = mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->ls),
	&(fract->end));
	i = 0;
	while (i < THREAD)
	{
		thread[i] = (t_fract*)ft_m(sizeof(t_fract));
		ft_memcpy(thread[i], fract, sizeof(t_fract));
		thread[i]->thread = i;
		pthread_create(&id[i], 0, calculate, thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(id[i], 0);
		free(thread[i++]);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	mlx_destroy_image(fract->mlx, fract->img);
}
