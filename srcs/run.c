/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:30:13 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/10 15:26:29 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

#include <mlx.h>

void		infos(t_fract *fract)
{
	char	*tmp;

	mlx_string_put(fract->mlx, fract->win, 0, 0, 0x00ff00, "ZOOM");
	mlx_string_put(fract->mlx, fract->win, 50, 0, 0xffffff,
	(tmp = ft_itoa(fract->zoom * 100)));
	free(tmp);
}

void		draw(t_fract *fract)
{
	mlx_clear_window(fract->mlx, fract->win);
	if (fract->type == 'm')
		mandelbrot(fract);
	infos(fract);
}

int			mouse(int button, int x, int y, void *param)
{
	draw(param);
	return (1);
}

int			key(int keycode, void *param)
{
	t_fract		*fract;

	fract = param;
	if (keycode == 69 || (keycode == 78 && fract->zoom > 0.25))
		fract->zoom *= keycode == 69 ? 2 : 0.5;
	else if (keycode == 24 || (keycode == 27 && fract->iter > 25))
		fract->iter *= keycode == 24 ? 2 : 0.5;
	else if (keycode == 53)
		exit(0);
	else
		 return (1);
	draw(fract);
	return (1);
}

int			expose(void *param)
{
	draw(param);
	return (1);
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
	mlx_key_hook(win, key, fract);
	mlx_expose_hook(win, expose, fract);
	mlx_mouse_hook(win, mouse, fract);
	mlx_loop(mlx);
}
