/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:34:05 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:41:48 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	if (!(tab = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			tab[j++] = ft_strsub(s, i, len);
			i += len;
		}
	tab[j] = 0;
	return (tab);
}
