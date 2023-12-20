/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:10 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/23 15:30:08 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	char	*new;

	if (!s1 ||!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(size, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, size);
	ft_strlcat(new, s2, size);
	return (new);
}
