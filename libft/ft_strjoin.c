/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:00:05 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:31:39 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		len;
	char	*str;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	len = 0;
	while (s2[len])
		str[index++] = s2[len++];
	return (str);
}
