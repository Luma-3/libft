/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:55:33 by jbrousse          #+#    #+#             */
/*   Updated: 2024/02/29 14:56:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	new = ft_calloc(n + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
