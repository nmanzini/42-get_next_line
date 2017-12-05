/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/12/05 18:06:18 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*str;
	char	**pointer;
	int		counter;
	int		returned;

	pointer = &str;
	counter = 1;
	fd = open("./sample", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error opening");
		return (0);
	}
	while ((returned = get_next_line(fd, pointer)) && counter < 20)
	{
		ft_putnbr(counter++);
		ft_putchar('\t');
		ft_putnbr(ft_strlen(str));
		ft_putchar('\t');
		ft_putendl(str);
	}
	free(str);
	if (close(fd) == -1)
		return (0);
	return (0);
}
