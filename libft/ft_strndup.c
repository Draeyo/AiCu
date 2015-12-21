/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:25:17 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:34:14 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if (!(str = ft_memalloc(n + 1)))
		return (NULL);
	ft_memcpy(str, s, n);
	str[n] = 0;
	return (str);
}
