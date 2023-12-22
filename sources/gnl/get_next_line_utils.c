/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:23:17 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/22 15:58:20 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stach_buffjoin(char *stach, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!stach)
	{
		stach = (char *)malloc(sizeof(char) * 1);
		stach[0] = '\0';
	}
	if (!stach || !buffer)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(stach) + ft_strlen(buffer) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (stach[++i])
		str[i] = stach[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(stach) + ft_strlen(buffer)] = '\0';
	free(stach);
	return (str);
}
