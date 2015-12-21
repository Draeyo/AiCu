/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:18:18 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/21 22:20:23 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void	ft_putstr2(char *s1, char c, char *s2)
{
	write(1, s1, ft_strlen(s1));
	write(1, &c, 1);
	write(1, s2, ft_strlen(s2));
}

int		ft_player_error2(int *board, int i, int lines)
{
	ft_putstr("Not enough matches on this line, try again.\n\n");
	return (ft_player_move(board, i, lines));
}

int		ft_player_error(int *board, int i, int lines)
{
	ft_putstr("Wrong input, please put a number between 1 and 3.\n\n");
	return (ft_player_move(board, i, lines));
}

int		ft_player_move(int *board, int i, int lines)
{
	char	buf[BUFF_SIZE];
	int		j;

	j = 0;
	ft_putstr("There is still ");
	ft_putnbr(board[i]);
	ft_putstr(" match(es) on this line, how much do you want to remove ?\n");
	while (!ft_strstr(buf, "\n"))
		read(0, &buf[j++], 1);
	buf[2] = '\0';
	if (j > 2 || buf[0] < '1' || buf[0] > '3')
		return (ft_player_error(board, i, lines));
	if (buf[0] - '0' > board[i])
		return (ft_player_error2(board, i, lines));
	board[i] -= (buf[0] - '0');
	if (i == 0 && board[i] == 0)
		return (0);
	ft_putstr2("\nYou have removed ", buf[0], " match(es).\n");
//	ft_display_board(board, lines);
	ft_putstr("Computer's turn\n");
	return (0);
}

int		ft_play(int *board, int *mode, int lines, int first)
{
	int	i;

	i = lines - 1;
	if (!first)
		ft_reduce(board, i, mode, lines);
	else
	{
		ft_putstr("You begin ! Press enter to play\n");
		ft_press_enter();
	}
	ft_display_board(board, lines);
	while (i >= 0)
	{
		while (board[i] > 0)
		{
			ft_player_move(board, i, lines);
			if (board[i] == 0)
				if (i-- == 0)
					return (ft_print_results(1));
			ft_comp_move(board, i, mode[i], lines);
		}
		if (board[i] == 0)
			i--;
	}
	return (ft_print_results(0));
}
