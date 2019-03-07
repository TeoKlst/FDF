/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspaceall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:53:09 by tkelest           #+#    #+#             */
/*   Updated: 2018/05/31 15:53:22 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspaceall(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || \
			c == '\v' || c == '\f')
		return (1);
	return (0);
}