/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:22:30 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/22 13:34:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier_type(char c, t_format *form_handle)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (c == form_handle[i].specifier)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

int	ft_in_specifier(char c)
{
	return (ft_is_specifier(c) || ft_is_flag(c) || ft_isdigit(c));
}
