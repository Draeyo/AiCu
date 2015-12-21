/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:04:06 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:36:31 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		index;
	int		len;

	index = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isblank(s[index]))
		index++;
	while (ft_isblank(s[len - 1]))
		len--;
	return (ft_strsub(s, index, (len != 0) ? len -= index : len));
}
