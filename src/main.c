/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:04:45 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/05 13:46:02 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

void	ft_assign_x_y(t_m u, t_coords *vertex, char *z_store)
{
	while (u.vertex_i < u.vertex_max)
	{
		if (u.w_i >= u.map_width)
		{
			u.h_i_count++;
			vertex[u.vertex_i].y = (u.h_i_count * 20);
			u.w_i = 0;
		}
		if (u.h_i < u.map_width)
		{
			u.h_i++;
			vertex[u.vertex_i].y = (u.h_i_count * 20 + 250);
			vertex[u.vertex_i].x = ((u.h_i * 20) + u.h_multi + 250);
			if (z_store[u.vertex_i] == '+')
				vertex[u.vertex_i].y -= 15;
			if (z_store[u.vertex_i] == '-')
				vertex[u.vertex_i].y += 15;
		}
		if (u.h_i == u.map_width)
		{
			u.h_i = 0;
			u.h_multi -= 22;
		}
		ft_w_i_vertex_i_plus(&u);
	}
}

void	ft_draw_grid(t_m u, t_coords *vertex, t_env e)
{
	u.i = 0;
	u.j = 1;
	u.w_horizontal = u.map_width;
	while (u.j < u.vertex_max)
	{
		if (u.j == u.w_horizontal)
		{
			ft_i_j_plus(&u);
			u.w_horizontal += u.map_width;
		}
		ft_line(u, vertex, e);
		ft_i_j_plus(&u);
		u.vertex_i++;
	}
	u.i = 0;
	u.j = 0 + u.map_width;
	u.w_horizontal = u.map_width;
	while (u.j < u.vertex_max)
	{
		ft_line(u, vertex, e);
		ft_i_j_plus(&u);
	}
}

int		main(int argc, char **argv)
{
	t_env		e;
	t_m			m;
	t_read		r;
	t_coords	vertex[50000];
	char		*z_store;

	if (argc == 2)
	{
		ft_assign(&m, &r);
		r.fd = open(argv[1], O_RDONLY);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 1024, 720, "FDF");
		ft_read(&r, &m);
		if (((m.vertex_max = ft_array_count(r.str2)) > 50000))
			return (0);
		z_store = ft_z_store(r.str2, m.vertex_max);
		m.h_multi = 88;
		ft_assign_x_y(m, vertex, z_store);
		m.vertex_i = 0;
		ft_draw_grid(m, vertex, e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
