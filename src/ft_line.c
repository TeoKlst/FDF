/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:08:42 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/05 13:44:24 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_data(t_line *l, t_m u, t_coords *vertex)
{
	l->x0 = vertex[u.i].x;
	l->y0 = vertex[u.i].y;
	l->x1 = vertex[u.j].x;
	l->y1 = vertex[u.j].y;
}

void	ft_line(t_m u, t_coords *vertex, t_env e)
{
	t_line	l;

	ft_data(&l, u, vertex);
	l.dx = abs(l.x1 - l.x0);
	l.sx = l.x0 < l.x1 ? 1 : -1;
	l.dy = abs(l.y1 - l.y0);
	l.sy = l.y0 < l.y1 ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		mlx_pixel_put(e.mlx, e.win, l.x0, l.y0, CYAN);
		if (l.x0 == l.x1 && l.y0 == l.y1)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx)
		{
			l.err -= l.dy;
			l.x0 += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.err += l.dx;
			l.y0 += l.sy;
		}
	}
}
