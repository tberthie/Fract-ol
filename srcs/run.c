/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:30:13 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/28 18:05:54 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_fract *fract)
{
	char	*tmp;

	mlx_clear_window(fract->mlx, fract->win);
	render(fract);
	mlx_string_put(fract->mlx, fract->win, 0, 0, 0x00ff00, "ZOOM");
	mlx_string_put(fract->mlx, fract->win, 50, 0, 0xffffff,
	(tmp = ito(fract->zoom)));
	free(tmp);
	if (fract->type != 'T')
	{
		mlx_string_put(fract->mlx, fract->win, 0, 20, 0x00ff00, "ITER");
		mlx_string_put(fract->mlx, fract->win, 50, 20, 0xffffff,
		(tmp = ito(fract->iter)));
		free(tmp);
	}
	if (fract->type == 'j')
	{
		mlx_string_put(fract->mlx, fract->win, 0, 40, 0x00ff00, "LOCK");
		mlx_string_put(fract->mlx, fract->win, 50, 40, 0xffffff,
		fract->lock ? "1" : "0");
	}
}

void		run(t_fract *fract)
{
	void	*mlx;
	void	*win;

	if (!(mlx = mlx_init()) ||
	!(win = mlx_new_window(mlx, WINX, WINY, "y u readin dis")))
	{
		ft_print(2, "fractol: an error has occured\n");
		return ;
	}
	fract->mlx = mlx;
	fract->win = win;
	draw(fract);
	mlx_hook(fract->win, 6, (1L << 6), move, fract);
	mlx_key_hook(fract->win, key, fract);
	mlx_mouse_hook(fract->win, mouse, fract);
	mlx_expose_hook(fract->win, expose, fract);
	mlx_loop(mlx);
}
