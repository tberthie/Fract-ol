/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:55:33 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/10 13:20:27 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINX	1920
# define WINY	1080

# define ITER	50

typedef struct		s_fract
{
	char	type;
	float	zoom;
	int		iter;

	void	*mlx;
	void	*win;
}					t_fract;

t_fract				*setup(char fract);
void				run(t_fract *fract);

void				mandelbrot(t_fract *fract);

#endif
