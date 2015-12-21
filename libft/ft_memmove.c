/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:33:14 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:41:00 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *swap;

	if (!(swap = (void*)malloc(len)))
		return (NULL);
	if (swap)
	{
		ft_memcpy(swap, src, len);
		ft_memcpy(dst, swap, len);
		free(swap);
	}
	return (dst);
}
