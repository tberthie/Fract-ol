/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:51:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/12 16:00:36 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

#include <unistd.h>

static int	getfractal(char *str)
{
	if (!ft_strcmp(str, "j") || !ft_strcmp(str, "julia")
	|| !ft_strcmp(str, "m") || !ft_strcmp(str, "mandelbrot"))
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	t_fract		*fract;

	if (ac != 2 || !getfractal(av[1]))
		write(1, "usage: fractol [julia/mandelbrot]\n", 35);
	else if ((fract = setup(av[1][0])))
		run(fract);
	return (0);
}
