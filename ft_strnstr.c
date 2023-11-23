/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:55:50 by luma              #+#    #+#             */
/*   Updated: 2023/11/23 15:48:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	int				j;
	char			*tmp_str;

	if (!str ||!to_find)
		return (NULL);
	i = 0;
	tmp_str = (char *)str;
	if (*to_find == 0)
		return (tmp_str);
	while (tmp_str[i] && len > i)
	{
		j = 0;
		while (to_find[j] == tmp_str[i + j] && i + j < len)
		{
			if (to_find[j + 1] == 0)
				return (tmp_str + i);
			j++;
		}
		i++;
	}
	return (0);
}
