/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:59 by luma              #+#    #+#             */
/*   Updated: 2023/11/07 17:38:11 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned char	*tmp_s;

	if (!s)
		return (0);
	tmp_s = (unsigned char *)s;
	while (size--)
	{
		if (*tmp_s == (unsigned char)c)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (0);
}
