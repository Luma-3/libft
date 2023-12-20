/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:35:22 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/22 16:55:55 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_s_format(t_format *form)
{
	form[0] = (t_format){'c', ft_format_char};
	form[1] = (t_format){'s', ft_format_str};
	form[2] = (t_format){'d', ft_format_int};
	form[3] = (t_format){'i', ft_format_int};
	form[4] = (t_format){'p', ft_format_ptr};
	form[5] = (t_format){'u', ft_format_uint};
	form[6] = (t_format){'x', ft_format_lowhex};
	form[7] = (t_format){'X', ft_format_uphex};
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}
