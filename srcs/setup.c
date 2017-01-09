/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:14:37 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 23:00:03 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <mlx.h>

int			key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (1);
}

int			expose(void *param)
{
	return (1);
}

void		pixel(void *mlx, void *win, int x, int y)
{
	int		z;

	z = 0;

	z1 = z0 ^ 2 + (x + iy)
	z2 = (x + iy) ^ 2 + (x + iy)

//	mlx_pixel_put(mlx, win, x, y, 0xffffff);
}

void		test(void *mlx, void *win)
{
	int		x;
	int		y;

	x = 0;
	while (x < 2000)
	{
		y = 0;
		while (y < 1000)
		{
			pixel(mlx, win, x, y);
			y++;
		}
		x++;
	}
}

void		setup(char	fract)
{
	void	*mlx;
	void	*win;

	if (!(mlx = mlx_init()) ||
	!(win = mlx_new_window(mlx, 2000, 1000, "why u readin this")))
		return ((void)ft_errret("fractol", "an error has occured", 0));
	{
		test(mlx, win);
		mlx_key_hook(win, key, 0);
		mlx_expose_hook(win, expose, 0);
		mlx_loop(mlx);
	}
}
