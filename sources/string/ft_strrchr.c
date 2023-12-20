/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:28:09 by luma              #+#    #+#             */
/*   Updated: 2023/11/08 17:25:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_oc;
	char	*str;

	last_oc = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			last_oc = str;
		str++;
	}
	if (*str == (char)c)
		last_oc = str;
	return (last_oc);
}
