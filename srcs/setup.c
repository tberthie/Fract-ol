/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:14:37 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/10 12:58:23 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>

t_fract		*setup(char type)
{
	t_fract		*fract;

	if (!(fract = malloc(sizeof(t_fract))))
		return (0);
	fract->type = type;
	fract->zoom = 1;
	fract->iter = ITER;
	return (fract);
}
