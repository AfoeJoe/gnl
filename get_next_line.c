/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <tkathy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:43:21 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/04 21:41:40 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_remainder(char **remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (*remainder)
	{
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			*line = *remainder;
			++p_n;
			*remainder =  ft_strdup(p_n);
		}
		else
		{
			*line = *remainder;
			*remainder = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*p_n;
	static char	*remainder;

	if ((fd < 0 || !line || (BUFFER_SIZE <= 0) || (read(fd, buf, 0) == -1)))
		return (-1);
	p_n = check_remainder(&remainder, line);
	while (!p_n && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			if(!(remainder = ft_strdup(++p_n)))
				return (-1);
		}
		if(!(*line = ft_strjoin(*line, buf)))
			return(-1);
	}
	return ((byte_read || p_n) ? 1 : 0);
}
