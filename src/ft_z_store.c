/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:34:05 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/05 14:57:59 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		double_positive(char *str, t_z_store *z)
{
	if (!(str[z->j] == '-') && (str[z->i] >= '1' && str[z->i] <= '9') &&
			(str[z->n] >= '0' && str[z->n] <= '9'))
	{
		z->z[z->l] = '+';
		z->l++;
	}
}

void		single_positive(char *str, t_z_store *z)
{
	if (!(str[z->j] == '-' || (str[z->j] >= '1' && str[z->j] <= '9')) &&
			(str[z->i] >= '1' && str[z->i] <= '9') && str[z->n] == ' ')
	{
		z->z[z->l] = '+';
		z->l++;
	}
}

void		single_negative(char *str, t_z_store *z)
{
	if (str[z->j] == '-' &&
			(str[z->i] >= '1' && str[z->i] <= '9') && str[z->n] == ' ')
	{
		z->z[z->l] = '-';
		z->l++;
	}
}

void		double_negative(char *str, t_z_store *z)
{
	if ((str[z->j] == '-') && (str[z->i] >= '1' && str[z->i] <= '9' &&
				str[z->n] >= '0' && str[z->n] <= '9'))
	{
		z->z[z->l] = '-';
		z->l++;
	}
}

char		*ft_z_store(char *str, int vertex_max)
{
	t_z_store	z;

	z.j = -1;
	z.i = 0;
	z.n = 1;
	z.l = 0;
	z.z = (char *)malloc(sizeof(char) * vertex_max);
	while (str[z.i] != '\0')
	{
		ft_neutral(str, &z);
		single_positive(str, &z);
		double_positive(str, &z);
		single_negative(str, &z);
		double_negative(str, &z);
		z.j++;
		z.i++;
		z.n++;
	}
	z.z[z.l] = '\0';
	return (z.z);
}
