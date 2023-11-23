/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:06:33 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/23 15:46:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	i;

	if (!src || !dst)
		return (0);
	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i] && (i + dst_len + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (size > 0)
		dst[dst_len + i] = 0;
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dst_len);
}
