/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:20:13 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/24 11:53:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*mem;

	if (!s)
		return (NULL);
	mem = s;
	while (len)
	{
		*mem = (unsigned char)c;
		mem++;
		len--;
	}
	return (s);
}
