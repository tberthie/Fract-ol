/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:30:13 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/12 15:44:41 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

#include <mlx.h>

void		draw(t_fract *fract)
{
	char	*tmp;

	mlx_clear_window(fract->mlx, fract->win);
	(fract->type == 'm') ? mandelbrot(fract) : 0;
	(fract->type == 'j') ? julia(fract) : 0;
	if (fract->type == 'm')
		mlx_string_put(fract->mlx, fract->win, 0, 0, 0x00ff00, "MANDELBROT");
	if (fract->type == 'j')
	{
		mlx_string_put(fract->mlx, fract->win, 0, 0, 0x00ff00, "JULIA");
		mlx_string_put(fract->mlx, fract->win, 0, 60, 0x00ff00, "LOCK");
		mlx_string_put(fract->mlx, fract->win, 50, 60, 0xffffff,
		fract->lock ? "1" : "0");
	}
	mlx_string_put(fract->mlx, fract->win, 0, 20, 0x00ff00, "ZOOM");
	mlx_string_put(fract->mlx, fract->win, 50, 20, 0xffffff,
	(tmp = ito(fract->zoom)));
	free(tmp);
	mlx_string_put(fract->mlx, fract->win, 0, 40, 0x00ff00, "ITER");
	mlx_string_put(fract->mlx, fract->win, 50, 40, 0xffffff,
	(tmp = ito(fract->iter)));
	free(tmp);
}

void		run(t_fract *fract)
{
	void	*mlx;
	void	*win;

	if (!(mlx = mlx_init()) ||
	!(win = mlx_new_window(mlx, WINX, WINY, "y u readin dis")))
		return ((void)ft_errret("fractol", "an error has occured", 0));
	fract->mlx = mlx;
	fract->win = win;
	draw(fract);
	mlx_hook(fract->win, 6, (1L << 6), move, fract);
	mlx_key_hook(fract->win, key, fract);
	mlx_mouse_hook(fract->win, mouse, fract);
	mlx_expose_hook(fract->win, expose, fract);
	mlx_loop(mlx);
}
