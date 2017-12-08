/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/12/08 14:21:39 by nmanzini         ###   ########.fr       */
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
		ft_putendl("error opening");
		return (0);
	}
	while ((result = get_next_line(2000, &line)))
	{
		if (result == -1)
		{
			ft_putendl("error");
			break ;
		}
		ft_putendl(line);
	}
	if (close(fd) == -1)
		return (0);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putendl("usage: printNextLine source_file");
	else if (argc > 2)
		ft_putendl("usage: printNextLine source_file");
	else
	{
		get_next(argv[1]);
	}
	return (1);
}
