/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:55:23 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/22 10:01:17 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin4(char *s1, char *s2, char *s3, char *s4)
{
	char	*new_str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + ft_strlen(s4) + 1;
	new_str = calloc(len, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, len);
	if (s2 != NULL)
		ft_strlcat(new_str, s2, len);
	if (s3 != NULL)
		ft_strlcat(new_str, s3, len);
	if (s4 != NULL)
		ft_strlcat(new_str, s4, len);
	return (new_str);
}
