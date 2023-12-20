/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:51:56 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/23 14:16:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_uint(va_list args, t_flags flags)
{
	unsigned int	value;
	char			*str;
	int				len;

	len = 0;
	value = va_arg(args, unsigned int);
	str = ft_uitoa(value);
	if (value == 0)
		len = write(1, "0", 1);
	else
	{
		if (flags.left == 1)
			len += ft_print_str(str);
		len += ft_pad_witdh(flags.width, ft_strlen(str), 0);
		if (flags.left == 0)
			len += ft_print_str(str);
	}
	free(str);
	return (len);
}

size_t	ft_intlen(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int nb)
{
	size_t	len;
	char	*new;

	len = ft_intlen(nb);
	new = ft_calloc(len + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (nb != 0)
	{
		new[len - 1] = nb % 10 + 48;
		nb /= 10;
		len --;
	}
	return (new);
}
