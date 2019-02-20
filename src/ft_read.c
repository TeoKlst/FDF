/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 12:32:18 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/05 12:34:16 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_read(t_read *r, t_m *m)
{
	while (get_next_line(r->fd, &r->line) == 1)
	{
		r->str1 = r->line;
		m->map_width = ft_array_count(r->line);
		m->map_height++;
		r->str2 = ft_strjoin(r->str1, r->str2);
		free(r->line);
	}
	close(r->fd);
}
