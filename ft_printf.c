/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:06:11 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/24 15:59:29 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	format_func[8];
	size_t		len;

	if (!format)
		return (-1);
	va_start(args, format);
	create_s_format(format_func);
	len = create_line((char *)format, format_func, args);
	va_end(args);
	return (len);
}

int	create_line(char *strf, t_format *format, va_list args)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (strf[i])
	{
		if (strf[i] == '%' && strf[i + 1] != '\0')
			i += ft_read_spec(strf + i, format, args, &len);
		else if (strf[i] != '%')
		{
			ft_putchar_fd(strf[i++], 1);
			len++;
		}
		else
			i++;
	}
	return (len);
}

int	ft_read_spec(char *start, t_format *format, va_list args, size_t *len)
{
	int		i;
	t_flags	flags;

	i = 0;
	flags = init_flags();
	while (start[++i])
	{
		ft_flags_specifier(start[i], &flags, format);
		if (ft_is_specifier(start[i]))
		{
			*len += format[flags.specifier].handler(args, flags);
			break ;
		}
		else if (start[i] == '%')
		{
			*len += ft_print_str("%");
			break ;
		}
	}
	return (i + 1);
}

void	ft_flags_specifier(char c, t_flags *flags, t_format *format)
{
	if (c == '-')
	{
		flags->left = 1;
		flags->zero = 0;
	}
	else if (c == '#')
		flags->hash = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0' && flags->left == 0 && flags->width == 0)
		flags->zero = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (ft_isdigit(c))
		flags->width = flags->width * 10 + (c - 48);
	else if (ft_is_specifier(c))
		flags->specifier = ft_specifier_type(c, format);
}
