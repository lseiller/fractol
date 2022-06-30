/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:02:31 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:45:54 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_no_nl(char *buffer)
{
	char		*line;
	size_t		i;
	size_t		size;

	size = ft_strlen(buffer);
	i = 0;
	line = ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*fill_nl(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	size;

	size = ft_strchr(buffer, '\n') - buffer;
	i = 0;
	line = ft_calloc(size + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	ft_strrcpy(buffer, buffer, size + 1);
	return (line);
}

static char	*ft_error(char *line, char *line2)
{
	if (line)
		free(line);
	if (line2)
		free(line2);
	return (NULL);
}

char	*fill_join(char *line, char *buffer, int fd, int read_value)
{
	char	*line2;

	if (ft_strchr(buffer, '\n') == NULL)
	{
		line2 = fill_no_nl(buffer);
		if (!line2)
			return (NULL);
		ft_strmcpy(buffer, buffer, read_value);
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == 0)
		{
			line = strjoin_gnl(line, line2);
			*buffer = '\0';
		}
		else if (read_value < 0)
			return (ft_error(line, line2));
		else
			line = fill_join(strjoin_gnl(line, line2), buffer, fd, read_value);
	}
	else
	{
		line2 = fill_nl(buffer);
		line = strjoin_gnl(line, line2);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[512][BUFFER_SIZE + 1];
	char		*line;
	int			read_value;

	if (fd < 0 || fd > 512)
		return (NULL);
	if (!*(*(buffer + fd)))
		read_value = read(fd, *(buffer + fd), BUFFER_SIZE);
	else
		read_value = 1;
	if (read_value <= 0)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	line = fill_join(line, buffer[fd], fd, read_value);
	return (line);
}
