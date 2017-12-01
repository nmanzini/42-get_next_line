/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 22:12:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/11/30 21:30:26 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchro(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_write(int fd, int size, char *dst)
{
	int ret;
	char *buf2;
	int seen;

	seen = 0;
	buf2 = ft_strnew(BUFF_SIZE);
	while((ret = read(fd, buf2, BUFF_SIZE)))
	{
		ft_strlcat(dst,buf2,size);
		if ((seen+= ret) > size)
			break;
	}
	if (ret == 0)
		return (0);
	else if (ret > 0)
		return (1);
	else
		return (-1);
}

int get_next_line(const int fd, char **line)
{
	int ret;
	char *buf;
	int prev_offset;
	int offset;
	int verbose = 0;

	offset = 0;
	prev_offset = lseek(fd, 0, SEEK_CUR);

	if (verbose)
	{
		ft_putstr("starting offset\t\t\t\t");
		ft_putnbre(prev_offset);
		ft_putendl("searching \t\t\t\t\t----");
	}

	buf = ft_strnew(BUFF_SIZE);


	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ft_strchro(buf, '\n') >= 0)
		{
			offset += ft_strchro(buf, '\n');
			break;
		}
		offset += ret;
	}

	if(verbose)
	{
		ft_putstr("ideal offset\t\t\t\t");
		ft_putnbre(prev_offset + offset);
	}

	lseek(fd, prev_offset,SEEK_SET);



	
	*line = ft_strnew(offset);

	if(verbose)
	{
		ft_putstr("writing\t\t\t\t\t\t");
		ft_putnbre(offset);
	}


	ft_write(fd,offset + 1,*line);

	if (verbose)
	{
		ft_putstr("after writing offset\t\t");
		ft_putnbre(lseek(fd, 0, SEEK_CUR));
		ft_putstr("repositioned offset\t\t\t");
	}

	lseek(fd, prev_offset + offset + 1,SEEK_SET);
	
	if (verbose)
		ft_putnbre(lseek(fd, 0, SEEK_CUR));

	if (ret == 0)
			return (0);
	else if (ret > 0)
		return (1);
	else
		return (-1);
}
