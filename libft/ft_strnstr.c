/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:47:48 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:41:53 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (!(*s2))
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && j < n)
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
