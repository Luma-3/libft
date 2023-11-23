/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:03:28 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/08 14:47:42 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (!src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (src < dst)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
