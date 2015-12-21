/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:57:46 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/21 19:48:17 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		ft_check_if(int *board, int index)
{
	if (!(ft_isvalid(board[index])))
		return (-1);
	return (0);
}

int		ft_read_input(int fd)
{
	char	*buf;
	char	*input;
	int		ret;
	int		i;

	i = 0;
	if (!(buf = (char*)malloc(sizeof(*buf) * BUFF_SIZE)))
		return (0);
	if (fd == 0)
		while (!ft_strstr(buf, "\n\n"))
			ret = read(fd, &buf[i++], 1);
	else
		while ((ret = read(fd, &buf[i], 1)))
			i++;
	buf[i] = '\0';
	input = ft_strdup(buf);
	return (ft_core(input));
}

int		ft_read_file(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(2, "open() failed\n", 14);
		return (1);
	}
	ft_read_input(fd);
	if (close(fd) == -1)
	{
		write(2, "close() failed\n", 15);
		return (1);
	}
	return (0);
}

int		ft_error(void)
{
	write(2, "ERROR\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
		return (ft_error());
	if (argc == 2)
		return (ft_read_file(argv[1]));
	else
		return (ft_read_input(0));
	return (0);
}
