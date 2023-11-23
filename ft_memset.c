/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:20:13 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/07 17:11:36 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*mem;

	if (!s)
		return (NULL);
	i = 0;
	mem = (unsigned char *)s;
	while (i < len)
		mem[i++] = c;
	return (s);
}
