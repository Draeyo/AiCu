/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:52:18 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:42:43 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t count;

	count = 0;
	while (count < n && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	if (count < n)
		while (count < n)
			dst[count++] = '\0';
	return (dst);
}
