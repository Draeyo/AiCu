/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 23:08:08 by rmicolon          #+#    #+#             */
/*   Updated: 2015/12/21 23:28:57 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

char	*ft_bufextend(char *old)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	len = 0;
	new = NULL;
	if (old)
		len = ft_strlen(old);
	if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}
