/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:51:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/13 17:42:37 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

#include <unistd.h>

static int	getfractal(char *str)
{
	if (!ft_strcmp(str, "julia"))
		return ('j');
	if (!ft_strcmp(str, "mandelbrot"))
		return ('m');
	if (!ft_strcmp(str, "ship"))
		return ('s');
	if (!ft_strcmp(str, "bird"))
		return ('b');
	return (0);
}

int			main(int ac, char **av)
{
	t_fract		*fract;
	int			type;

	if (ac != 2 || !(type = getfractal(av[1])))
		write(1, "usage: fractol [julia/mandelbrot/bird/ship]\n", 45);
	else if ((fract = setup(type)))
		run(fract);
	return (0);
}
