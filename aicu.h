/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 23:55:12 by rmicolon          #+#    #+#             */
/*   Updated: 2015/12/21 23:26:40 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 50

int		ft_error(void);
int		ft_player_move(int *board, int i, int lines);
int		ft_comp_move(int *board, int i, int mode, int lines);
void	ft_analysis(int *board, int lines);
int		ft_play(int *board, int *mode, int lines, int first);
int		ft_check_if(int *board, int index);
int		ft_core(char *input);
int		ft_isvalid(int nb);
void	ft_press_enter(void);
void	ft_display_board(int *board, int lines);
int		ft_print_results(int result);
void	ft_reduce(int *board, int i, int *mode, int lines);
void	ft_roll(void);
void	ft_separator(void);
char	*ft_bufextend(char *old);

#endif
