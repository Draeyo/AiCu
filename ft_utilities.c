/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:00:44 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/21 19:38:45 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		ft_isvalid(int nb)
{
	if (nb >= 1 && nb <= 10000)
		return (1);
	return (0);
}

int		ft_max(int *board, int lines)
{
	int	i;
	int	max;

	i = 1;
	max = board[0];
	while (i < lines)
	{
		if (board[i] > max)
			max = board[i];
		i++;
	}
	return (max);
}

void	ft_press_enter(void)
{
	size_t	i;
	char	buf[BUFF_SIZE];

	i = 0;
	while (!ft_strstr(buf, "\n"))
		read(0, &buf[i++], 1);
	buf[1] = '\0';
	if (i > 1)
	{
		ft_putstr("Please press enter only.");
		ft_press_enter();
	}
}

int		ft_print_results(int result)
{
	ft_putstr("\n\nGAME OVER\n\n");
	if (result)
		ft_putstr("COMPUTER WON... AS ALWAYS !\nYou may try again...\n\n");
	else
		ft_putstr("You won... WAIT WHAT?!!\n\n");
	return (0);
}

void	ft_display_board(int *board, int lines)
{
	int		center;
	int		i;
	int		j;

	center = ft_max(board, lines);
	i = 0;
	write(1, "\n", 1);
	while (i < lines)
	{
		j = 0;
		while (j < (center - board[i]) / 2)
		{
			write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < board[i])
		{
			write(1, "|", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
