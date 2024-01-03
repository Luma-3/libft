/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:42:37 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/03 15:49:10 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_char(va_list args, t_flags flags)
{
	char	value;
	int		len;

	len = 0;
	value = va_arg(args, int);
	if (flags.left == 1)
		len += ft_print_char(value);
	len += ft_pad_witdh(flags.width, 1, 0);
	if (flags.left == 0)
		len += ft_print_char(value);
	return (len);
}

int	ft_format_str(va_list args, t_flags flags)
{
	char	*value;
	int		len;

	len = 0;
	value = va_arg(args, char *);
	if (value == NULL)
		value = "(null)";
	if (flags.left == 1)
		len += ft_print_str(value);
	len += ft_pad_witdh(flags.width, ft_strlen(value), 0);
	if (flags.left == 0)
		len += ft_print_str(value);
	return (len);
}

int	ft_format_int(va_list args, t_flags flags)
{
	int		value;
	char	*num;
	int		len;

	len = 0;
	value = va_arg(args, int);
	num = ft_itoa(value);
	if (flags.left == 1)
	{
		len += ft_print_positive(flags, value);
		len += ft_print_str(num);
	}
	len += ft_pad_witdh(flags.width - flags.plus - flags.space,
			ft_strlen(num), 0);
	if (flags.left == 0)
	{
		len += ft_print_positive(flags, value);
		len += ft_print_str(num);
	}
	free(num);
	return (len);
}

int	ft_print_positive(t_flags flags, long value)
{
	int	i;

	i = 0;
	if (value > -1)
	{
		if (flags.space == 1 && flags.plus == 0)
			i = ft_print_char(' ');
		else if (flags.plus == 1)
			i = ft_print_char('+');
	}
	return (i);
}
