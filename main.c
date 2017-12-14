/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/12/14 18:54:08 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next(char *path)
{
	int		fd;
	char	*line;
	int		result;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error opening: ");
		ft_putendl(path);
		return (1);
	}
	while ((result = get_next_line(fd, &line)))
	{
		if (result == -1)
		{
			ft_putstr("error getting next line in: ");
			ft_putendl(path);
			return(1);
		}
		ft_putendl(line);
	}
	if (close(fd) == -1)
	{
		ft_putstr("error closing file: ");
		ft_putendl(path);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		ft_putendl("usage: printfile source_files");
	while (i < ac)
	{
		if (get_next(av[i++]))
			return (1);
	}
	return (0);
}
