/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:52:29 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		count++;
		ptr /= 16;
	}
	return (count);
}

void	ft_put_ptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	*ft_print_ptr(unsigned long long ptr, int *len)
{
	*len += write(1, "0x", 2);
	ft_put_ptr(ptr);
	*len += ft_ptrlen(ptr);
	return (len);
}

int	ft_format_ptr(va_list args, t_flags flags)
{
	int				len;
	unsigned long	ptr;

	len = 0;
	ptr = va_arg(args, unsigned long long);
	if (ptr == 0)
		len += write(1, "(nil)", 5);
	else
	{
		if (flags.left == 1)
			ft_print_ptr(ptr, &len);
		len += ft_pad_witdh(flags.width, ft_ptrlen(ptr) + 2, 0);
		if (flags.left == 0)
			ft_print_ptr(ptr, &len);
	}
	return (len);
}
