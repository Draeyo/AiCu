/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:20:15 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:43:16 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	count;
	int		len;

	count = 0;
	len = ft_strlen(s1);
	while (count < n)
		s1[len++] = s2[count++];
	s1[len] = '\0';
	return (s1);
}
