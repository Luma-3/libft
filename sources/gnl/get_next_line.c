/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:23:10 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/23 16:07:24 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stach[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (0);
	stach[fd] = ft_read_and_stach(stach[fd], fd);
	if (!stach[fd])
		return (0);
	line = ft_create_line(stach[fd]);
	stach[fd] = ft_reset_stach(stach[fd]);
	return (line);
}

char	*ft_read_and_stach(char *stach, int fd)
{
	char	*buffer;
	int		rd_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	rd_bytes = 1;
	while (!ft_strchr(stach, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[rd_bytes] = '\0';
		stach = stach_buffjoin(stach, buffer);
		if (!stach)
			return (NULL);
	}
	free(buffer);
	return (stach);
}

char	*ft_create_line(char *stach)
{
	int		i;
	char	*str;

	i = 0;
	if (!stach[i])
		return (0);
	while (stach[i] != '\n' && stach[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (stach[i] != '\n' && stach[i])
	{
		str[i] = stach[i];
		i++;
	}
	if (stach[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_reset_stach(char *stach)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stach[i] != '\n' && stach[i])
		i++;
	if (!stach[i])
	{
		free(stach);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stach) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (stach[i])
		str[j++] = stach[i++];
	str[j] = '\0';
	free(stach);
	return (str);
}
