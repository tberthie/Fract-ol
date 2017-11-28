/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:51:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/28 20:59:22 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (!ft_strcmp(str, "tricorn"))
		return ('t');
	if (!ft_strcmp(str, "tapis"))
		return ('T');
	if (!ft_strcmp(str, "arbre"))
		return ('a');
	return (0);
}

int			main(int ac, char **av)
{
	t_fract		*fract;
	int			type;

	if (ac != 2 || !(type = getfractal(av[1])))
		ft_print(2, "usage: fractol [%s]\n", USAGE);
	else if ((fract = setup(type)))
		run(fract);
	return (0);
}
