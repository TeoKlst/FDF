/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:55:44 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/03 17:56:24 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_flip(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
	{
		tmp[i] = str[i];
	}
	tmp[i] = '\0';
	return (tmp);
}
