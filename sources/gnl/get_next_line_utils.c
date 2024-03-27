/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:23:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/23 16:23:19 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	copy_stach(char *str, char *stach, char *buffer)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (stach[++i])
		str[i] = stach[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(stach) + ft_strlen(buffer)] = '\0';
}

char	*stach_buffjoin(char *stach, char *buffer)
{
	char	*str;

	if (!stach)
	{
		stach = (char *)malloc(sizeof(char) * 1);
		if (!stach)
			return (NULL);
		stach[0] = '\0';
	}
	if (!buffer)
	{
		free(stach);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stach) + ft_strlen(buffer) + 1));
	if (!str)
	{
		free(stach);
		free(buffer);
		return (NULL);
	}
	copy_stach(str, stach, buffer);
	free(stach);
	return (str);
}
