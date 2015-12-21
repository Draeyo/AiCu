/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 10:14:31 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/15 10:31:13 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_length(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (len + 1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_solve(char *str, int n, int len)
{
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
		len = ft_length(n) + 1;
	}
	else
		len = ft_length(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	if (sign == 1)
		str[0] = '-';
	ft_solve(str, n, len);
	return (str);
}
