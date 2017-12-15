/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:14:37 by tberthie          #+#    #+#             */
/*   Updated: 2017/12/07 22:20:16 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*setup(char type)
{
	t_fract		*fract;

	if (!(fract = malloc(sizeof(t_fract))))
		return (0);
	fract->type = type;
	fract->zoom = 0.5;
	fract->x = 0;
	fract->y = 0;
	fract->zr = 0;
	fract->zi = 0;
	fract->iter = ITER;
	fract->bpp = 32;
	fract->ls = WINX * 4;
	fract->end = 0;
	fract->lock = 0;
	return (fract);
}
