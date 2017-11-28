/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:24:38 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/28 18:17:22 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*ito(long double nb)
{
	int				len;
	long long		n;
	char			*s;

	len = 1;
	n = nb;
	while (n >= 10 && (n /= 10))
		len++;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len--] = 0;
	n = nb;
	while (n >= 10)
	{
		s[len--] = n % 10 + '0';
		n /= 10;
	}
	s[len] = n % 10 + '0';
	if ((s[0] <= '0' || s[0] >= '9') && ft_freeret(s, 1))
		return (ft_strdup("WTF ARE YOU DOING"));
	return (s);
}

int			color(long double i)
{
	if (i <= 0.16)
		return (((int)(32 * i / 0.16) << 16) + ((int)(7 + 100 * i /
		0.16) << 8) + (100 + 103 * i / 0.16));
	else if (i <= 0.42 && (i -= 0.16))
		return (((int)(32 + 205 * i / 0.26) << 16) + ((int)(107 + 148 * i /
		0.26) << 8) + (203 + 42 * i / 0.26));
	else if (i <= 0.6425 && (i -= 0.42))
		return (((int)(237 + 18 * i / 0.2225) << 16) + ((int)(255 - 85 * i /
		0.2225) << 8) + (255 - 255 * i / 0.2225));
	else if (i <= 0.8575 && (i -= 0.6425))
		return (((int)(255 - 255 * i / 0.215) << 16) + ((int)(170 - 168 * i /
		0.215) << 8));
	else
		return ((int)(2 - 2 * (i -= 0.8575) / 0.1425) << 8);
}
