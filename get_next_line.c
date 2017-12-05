/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 22:12:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/12/05 15:50:06 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strchr0(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c && s[i] != 0)
		s++;
	if (s[i] == (char)c)
		s[i] = 0;
}

int		str_handler(char *input, char **result, char **rest)
{
	char		*tmp;

	if (ft_strrchr(input, '\n'))
	{
		// ft_putendl("\t\tfound new line in input");
		*rest = ft_strcpy(*rest, &ft_strchr(input, '\n')[1]);
		ft_strchr0(input, 10);
		*result = ft_strcat(*result, input);
		return (1);
	}
	// ft_putendl("\t\tnot found new line");
	// ft_putendl(input);
	*result = ft_strcat(*result, input);
	tmp = ft_strnew(ft_strlen(*result) + BUFF_SIZE);
	tmp = ft_strcpy(tmp, *result);
	*result = tmp;
	return (0);
}

int		rest_handler(char **result, char **rest)
{
	char		*tmp;

	// ft_putendl("\t\tfound new line in input");
	tmp = ft_strdup(*rest);
	*rest = ft_strcpy(*rest, &ft_strchr(*rest, '\n')[1]);
	ft_strchr0(tmp, 10);
	*result = ft_strcat(*result, tmp);
	free(tmp); 
	return (1);
}

void		ft_strzero(char *input, int len)
{
	while (len--)
	{
		input[len] = 0;
	}
}

int		get_next_line(const int fd, char **line)
{
	static char *rest;
	char		*buf;
	char		*result;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (!rest)
	{
		// ft_putendl("\tallocating new REST");
		result = ft_strnew(BUFF_SIZE);
		rest = ft_strnew(BUFF_SIZE);
	}
	else
	{
		result = ft_strnew(BUFF_SIZE + ft_strlen(rest));
	}
	buf = ft_strnew(BUFF_SIZE);
	if (ft_strrchr(rest, '\n'))
	{
		// ft_putendl("\t\tfound \\n in  REST");
		rest_handler(&result, &rest);
		*line = result;
		return (1);
	}
	else
	{
		result = ft_strcat(result, rest);
		// ft_putendl("\t\tno \\n in  REST");
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			ft_putnbre(ret);

			if (ret < 0)
				return (-1);
			// ft_putstr("\treading - ");
			if (str_handler(buf, &result, &rest))
			{
				*line = result;
				return (1);
			}
			ft_strzero(buf,BUFF_SIZE);
		}

	}
	*line = result;
	if (buf[0] == 0 )
		return (0);
	else if (ret < 0)
		return (-1);
	return (1);
}
