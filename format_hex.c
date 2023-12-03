/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:41:05 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/22 17:54:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_uphex(va_list args, t_flags flags)
{
	unsigned int	value;
	int				len;

	len = 0;
	value = va_arg(args, unsigned int);
	if (value == 0)
		return (write(1, "0", 1));
	len += ft_hexlen(value);
	if (flags.left == 1)
	{
		if (flags.hash == 1)
			len += ft_print_str("0X");
		ft_put_hex(value, 'X');
	}
	len += ft_pad_witdh(flags.width, ft_hexlen(value), 0);
	if (flags.left == 0)
	{
		if (flags.hash == 1)
			len += ft_print_str("0X");
		ft_put_hex(value, 'X');
	}
	return (len);
}

int	ft_format_lowhex(va_list args, t_flags flags)
{
	unsigned int	value;
	int				len;

	len = 0;
	value = va_arg(args, unsigned int);
	if (value == 0)
		return (write(1, "0", 1));
	len += ft_hexlen(value);
	if (flags.left == 1)
	{
		if (flags.hash == 1)
			len += ft_print_str("0x");
		ft_put_hex(value, 'x');
	}
	len += ft_pad_witdh(flags.width, ft_hexlen(value), 0);
	if (flags.left == 0)
	{
		if (flags.hash == 1)
			len += ft_print_str("0x");
		ft_put_hex(value, 'x');
	}
	return (len);
}

void	ft_put_hex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format);
		ft_put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
		{
			if (format == 'X')
				ft_putchar_fd(nb - 10 + 'A', 1);
			else
				ft_putchar_fd(nb - 10 + 'a', 1);
		}
	}
}

int	ft_hexlen(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}
