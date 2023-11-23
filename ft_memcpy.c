/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:51:03 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/08 14:48:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	if (!dst)
		return (NULL);
	mem_dest = (unsigned char *)dst;
	mem_src = (unsigned char *)src;
	while (len > 0)
	{
		*mem_dest++ = *mem_src++;
		len--;
	}
	return (dst);
}
