/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:28:56 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/09 12:57:15 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc(size_t size)
{
	void	*array;

	array = (void *) malloc(size);
	if (!array)
		return (NULL);
	ft_memset(array, 0, size);
	return (array);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	if (nmemb > ((size_t) -1 / size))
		return (NULL);
	return (ft_memalloc(nmemb * size));
}
