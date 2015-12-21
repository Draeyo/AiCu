/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:47:37 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:40:42 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*zs1;
	const char	*zs2;

	i = 0;
	zs1 = (const char*)s1;
	zs2 = (const char*)s2;
	while (i < n)
	{
		if (zs1[i] != zs2[i])
			return ((unsigned char)zs1[i] - (unsigned char)zs2[i]);
		i++;
	}
	return (0);
}
