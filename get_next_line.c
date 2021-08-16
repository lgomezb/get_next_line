/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:49:23 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/01/09 14:06:01 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		new_line(char **aux, char **line)
{
	char	*out;
	char	*tmp;

	if ((out = ft_strchr(*aux, '\n')))
	{
		*out = 0;
		*line = ft_strdup(*aux);
		tmp = ft_strdup(++out);
		free(*aux);
		*aux = tmp;
	}
	else
	{
		*line = *aux;
		*aux = NULL;
		return (0);
	}
	return (1);
}

static int		result(char **aux, char **line, int res, int fd)
{
	if (res < 0)
		return (-1);
	else if (res == 0 && !aux[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (new_line(&aux[fd], line));
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*aux[4096];
	int				res;
	char			*tmp;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (!aux[fd])
			aux[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(aux[fd], buff);
			free(aux[fd]);
			aux[fd] = tmp;
		}
		if (ft_strchr(aux[fd], '\n'))
			break ;
	}
	return (result(aux, line, res, fd));
}
