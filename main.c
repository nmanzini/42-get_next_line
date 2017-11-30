/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/11/30 14:46:10 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		ret;
	char	**buf;
	int		counter;

	counter = 0;
	fd = open("./sample", O_RDONLY);
	ft_putnbre(fd);
	if (fd == -1)
	{
		ft_putendl("error opening");
		return (0);
	}
	while(get_next_line(ft,buff))
	{
		ft_putstr(buff)
	}
	free(buf);
	if (close(fd) == -1)
		return (0);
	return (0);
}
