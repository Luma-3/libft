/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:52:04 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/10 11:30:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr_begin(const char *s, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		while (s[i] == set[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

static int	ft_chr_end(const char *s, const char *set)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (set[j])
	{
		while (s[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(const char *s, const char *set)
{
	int		start;
	int		end;
	char	*strtrim;

	if (!s || !set)
		return (NULL);
	start = ft_chr_begin(s, set);
	end = ft_chr_end(s, set);
	strtrim = ft_substr(s, start, (end - start));
	return (strtrim);
}
