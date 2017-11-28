/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:55:33 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/28 20:59:28 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>

# define WINX	2000
# define WINY	1200
# define USAGE	"julia/mandelbrot/bird/ship/tricorn/tapis/arbre"

# define ITER	50
# define THREAD	8

typedef struct		s_fract
{
	char		type;
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixs;

	int			iter;
	long double	zoom;
	long double	x;
	long double	y;
	long double	zr;
	long double	zi;

	int			lock;
	int			bpp;
	int			ls;
	int			end;

	char		thread;
}					t_fract;

t_fract				*setup(char fract);
void				run(t_fract *fract);
void				draw(t_fract *fract);

int					mandelbrot(t_fract *fract, long double x, long double y);
int					julia(t_fract *fract, long double x, long double y);
int					ship(t_fract *fract, long double x, long double y);
int					bird(t_fract *fract, long double x, long double y);
int					tricorn(t_fract *fract, long double x, long double y);
int					tapis(t_fract *fract, long double x, long double y);
void				arbre(t_fract *fract);

int					mouse(int button, int x, int y, void *param);
int					key(int key, void *param);
int					expose(void *param);
int					move(int x, int y, void *param);

void				render(t_fract *fract);
char				*ito(long double nb);
int					color(long double i);

#endif
