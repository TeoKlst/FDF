/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:39:55 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/05 14:56:16 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WHITE 0x00FFFFFF
# define CYAN 0x00FFFFF

# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>

# include "libft.h"

typedef struct	s_coords
{
	int			x;
	int			y;
	int			z;
}				t_coords;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_z_store
{
	int			i;
	int			j;
	int			n;
	int			l;
	char		*z;
}				t_z_store;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			err;
	int			sx;
	int			sy;
	int			e2;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_line;

typedef struct	s_m
{
	int			vertex_max;
	int			map_width;
	int			map_height;
	int			vertex_i;
	int			w_i;
	int			h_i;
	int			h_i_count;
	int			h_multi;
	int			i;
	int			j;
	int			w_horizontal;
}				t_m;

typedef struct	s_read
{
	int			fd;
	char		*line;
	char		*str1;
	char		*str2;
	char		*store;
}				t_read;

typedef struct	s_fdf
{
	t_m			map;
	t_coords	points;
}				t_fdf;

void			ft_line(t_m u, t_coords *vertex, t_env e);
char			*ft_z_store(char *str, int vertex_max);
char			*ft_flip(char *str);
int				map_length(char *str);
int				ft_array_count(char *str);
void			ft_i_j_plus(t_m *u);
void			ft_w_i_vertex_i_plus(t_m *u);
void			ft_read(t_read *r, t_m *m);
void			ft_assign(t_m *m, t_read *r);
void			ft_neutral(char *str, t_z_store *z);
#endif
