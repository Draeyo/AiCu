/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:07:15 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/04 17:28:56 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(s1);
	while (s2[count])
		s1[len++] = s2[count++];
	s1[len] = '\0';
	return (s1);
}
