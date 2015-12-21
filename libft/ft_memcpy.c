/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:03:02 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/20 17:44:09 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sc;

	i = 0;
	sc = (char *)src;
	ds = (char *)dst;
	while (i < n)
	{
		ds[i] = sc[i];
		i++;
	}
	return (dst);
}
