/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 22:12:30 by nmanzini          #+#    #+#             */
/*   Updated: 2017/12/05 19:42:47 by nmanzini         ###   ########.fr       */
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

void	ft_strzero(char *input, int len)
{
	while (len--)
		input[len] = 0;
}

int		str_process(char *input, char **result)
{
	char		*tmp;

	if (ft_strrchr(input, '\n'))
	{
		tmp = ft_strdup(input);
		input = ft_strcpy(input, &ft_strchr(input, '\n')[1]);
		ft_strchr0(tmp, 10);
		*result = ft_strcat(*result, tmp);
		// free(tmp);
		return (1);
	}
	else
	{
		tmp = ft_strdup(*result);
		// free(result);
		*result = ft_strnew(ft_strlen(tmp) + ft_strlen(input));
		*result = ft_strcpy(*result, tmp);
		*result = ft_strcat(*result, input);
		ft_strzero(input, BUFF_SIZE);
		// free(tmp);
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (*buff != 0)
		if (str_process(buff, line))
			return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		if (str_process(buff, line))
			return (1);
	}
	if (**line == 0)
		return (0);
	return (1);
}


// moulitest fails with differend buff sizes, 
// buff 100000 -> 9 errors
// buff     50 -> 6 errors
// buff     20 -> 6 errors
// buff      5 -> 2 errors
// buff      2 -> 1 errors
