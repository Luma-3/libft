/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:22:16 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/01 11:26:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip_whitespaces(const char *prompt, int i)
{
	while (ft_iswhitespace(prompt[i]) == 1 && prompt[i])
		i++;
	return (i);
}
