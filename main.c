/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/11/30 21:21:51 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*str;
	char	**pointer;
	int		counter;

	pointer = &str;

	counter = 1;
	fd = open("./sample", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error opening");
		return (0);
	}
	while(get_next_line(fd,pointer))
	{
		ft_putnbr(counter++);
		ft_putchar(' ');
		ft_putnbr(ft_strlen(str));
		ft_putchar(' ');
		ft_putendl(str);
	}
	ft_putnbr(counter++);
	ft_putchar(' ');
	ft_putnbr(ft_strlen(str));
	ft_putchar(' ');
	ft_putendl(str);
	
	free(str);
	if (close(fd) == -1)
		return (0);
	return (0);
}
