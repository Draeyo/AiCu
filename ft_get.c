/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 23:37:43 by rmicolon          #+#    #+#             */
/*   Updated: 2015/12/21 22:54:56 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

char	*ft_get_row(char *input)
{
	char	*row;
	int		i;

	i = 0;
	while (input[i] && input[i] != '\n')
		i++;
	if (!(row = (char *)malloc(sizeof(*row) * i + 1)))
		return (NULL);
	i = 0;
	while (*input != '\n')
		row[i++] = *input++;
	row[i] = '\0';
	return (row);
}

int		*ft_get_board(char *input, int lines)
{
	int		*board;
	char	*row;
	int		i;

	i = 0;
	board = NULL;
	row = NULL;
	if (!(board = (int *)malloc(sizeof(*board) * lines)))
		return (NULL);
	while (i < lines)
	{
		if (!(row = ft_get_row(input)))
			return (NULL);
		while (*input && *input != '\n')
			input++;
		input++;
		board[i] = ft_atoi(row);
		free(row);
		i++;
	}
	while (i--)
		if (ft_check_if(board, i) == -1)
			board[0] = -1;
	return (board);
}

int		ft_count_lines(char *input)
{
	int	lines;
	int	index;

	lines = 0;
	index = 0;
	while (input[index])
	{
		if (input[index] == '\n')
			lines++;
		index++;
	}
	if (ft_strstr(input, "\n\n"))
		lines--;
	return (lines);
}

void	ft_reduce(int *board, int i, int *mode, int lines)
{
	ft_putendl("Computer plays first !");
	ft_putendl("Press enter to start...");
	ft_press_enter();
	ft_comp_move(board, i, mode[i], lines);
}

int		ft_core(char *input)
{
	int	*board;
	int	lines;

	lines = ft_count_lines(input);
	if (!(board = ft_get_board(input, lines)))
		return (1);
	if (board[0] == -1)
		return (ft_error());
	ft_display_board(board, lines);
	ft_analysis(board, lines);
	free(input);
	free(board);
	return (0);
}
