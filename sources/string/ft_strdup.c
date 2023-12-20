/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:59:32 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/09 14:16:24 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*new;

	size = ft_strlen(s);
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, size + 1);
	return (new);
}
