/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/12/07 19:43:12 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next(char *path)
{
	int		fd;
	char	*line;
	char	*str;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error opening");
		return (0);
	}
	str = ft_strdup("Lorem ipsum dolor sit amet");
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		// ft_putstr("ft_strlen(line) = ");
		// ft_putnbre(ft_strlen(line));
		// ft_putstr("strcmp(line, str) = ");
		// ft_putnbre(strcmp(line, str));
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
