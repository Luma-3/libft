/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:55:43 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/22 15:02:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.left = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	return (flags);
}

int	ft_is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '#' || c == '-' || c == '0' || c == '.')
		return (1);
	return (0);
}

int	ft_pad_witdh(int width, int size, int zero)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (width - size > i)
	{
		if (zero)
			count += ft_print_char('0');
		else
			count += ft_print_char(' ');
		i++;
	}
	return (count);
}
