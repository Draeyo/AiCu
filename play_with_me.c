/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_with_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 22:52:59 by rmicolon          #+#    #+#             */
/*   Updated: 2015/12/21 20:42:01 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		ft_win(int row)
{
	if (row % 4 == 0)
		return (3);
	else if (row % 4 == 1)
		return (1);
	else if (row % 4 == 2)
		return (1);
	else
		return (2);
}

int		ft_lose(int row)
{
	if (row % 4 == 0)
		return (1);
	else if (row % 4 == 1)
		return (1);
	else if (row % 4 == 2)
		return (2);
	else
		return (3);
}

int		ft_comp_move(int *board, int i, int mode, int lines)
{
	int		play;

	if (mode)
		play = ft_win(board[i]);
	else
		play = ft_lose(board[i]);
	ft_putstr("\nComputer has removed ");
	ft_putnbr(play);
	ft_putstr(" match(es).\n");
	board[i] -= play;
	ft_display_board(board, lines);
	return (0);
}

int		*ft_getmode(int *line_type, int lines)
{
	int		*mode;
	int		i;

	if (!(mode = (int *)malloc(sizeof(*mode) * lines)))
		return (NULL);
	mode[0] = 1;
	i = 1;
	while (i < lines)
	{
		if (line_type[i - 1] == 2)
			mode[i] = 1;
		else if (line_type[i - 1] == 2 && mode[i - 1] == 1)
			mode[i] = 0;
		else if (line_type[i - 1] == mode[i - 1])
			mode[i] = 1;
		else if (line_type[i - 1] != mode[i - 1])
			mode[i] = 0;
		i++;
	}
	return (mode);
}

void	ft_analysis(int *board, int lines)
{
	int		*mode;
	int		*line_type;
	int		first;
	int		i;

	line_type = (int *)malloc(sizeof(*line_type) * lines);
	i = 0;
	while (i < lines)
	{
		if (board[i] % 4 == 0)
			line_type[i] = 1;
		else if (board[i] % 4 == 1)
			line_type[i] = 0;
		else
			line_type[i] = 2;
		i++;
	}
	mode = ft_getmode(line_type, lines);
	first = 0;
	if (mode[lines - 1] != line_type[lines - 1] && line_type[lines - 1] != 2)
		first = 1;
	ft_play(board, mode, lines, first);
}
