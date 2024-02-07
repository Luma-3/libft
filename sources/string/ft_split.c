/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:47:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/02/07 15:00:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

static void	ft_set_tab(char **tab, const char *s, char c)
{
	int	i;
	int	len;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			tab[words] = ft_calloc(len + 1, sizeof(char));
			if (!tab[words])
				return ;
			ft_strlcpy(tab[words], (s + i), len + 1);
			words++;
			i += len;
		}
		else
			i++;
	}
	tab[words] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (words <= 0)
		return (NULL);
	tab = ft_calloc(words + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	ft_set_tab(tab, s, c);
	return (tab);
}
