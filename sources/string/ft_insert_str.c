/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:36:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/27 18:38:39 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_insert_data(char *str,
							const char *insert_data,
							const char *token,
							int index)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = ft_calloc(sizeof(char), ft_strlen(str)
			- ft_strlen(token) + ft_strlen(insert_data) + 1);
	if (new_str == NULL)
		return (str);
	while (str[i] && i < index)
		new_str[j++] = str[i++];
	i = 0;
	while (insert_data[i])
		new_str[j++] = insert_data[i++];
	i = index + ft_strlen(token);
	while (str[i])
		new_str[j++] = str[i++];
	return (new_str);
}

char	*ft_insert_str(char *arg,
						const char *insert_data,
						const char *token,
						int index)
{
	char	*new_arg;

	if (insert_data == NULL)
		return (arg);
	while (arg[index] != '\0'
		&& ft_strncmp(arg + index, token, ft_strlen(token)) != 0)
		index++;
	if (arg[index] == '\0')
		return (arg);
	new_arg = copy_insert_data(arg, insert_data, token, index);
	if (new_arg == arg)
		return (arg);
	free(arg);
	return (new_arg);
}
