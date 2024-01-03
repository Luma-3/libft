/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:10:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/03 15:48:37 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "libft.h"

typedef struct s_flags
{
	int	width;
	int	zero;
	int	left;
	int	space;
	int	plus;
	int	hash;
	int	specifier;
}				t_flags;

typedef struct s_format
{
	char	specifier;
	int		(*handler)(va_list args, t_flags flags);
}				t_format;

int		ft_printf(const char *format, ...);

int		create_line(char *strf, t_format *format, va_list args);
void	ft_flags_specifier(char c, t_flags *flags, t_format *format);
int		ft_read_spec(char *start, t_format *format, va_list args, size_t *len);

void	create_s_format(t_format *form);
int		ft_print_str(char *str);
int		ft_print_char(char c);

int		ft_specifier_type(char c, t_format *form_handle);
int		ft_in_specifier(char c);
int		ft_is_specifier(char c);

int		ft_format_char(va_list args, t_flags flags);
int		ft_format_str(va_list args, t_flags flags);
int		ft_format_int(va_list args, t_flags flags);
int		ft_format_ptr(va_list args, t_flags flags);
int		ft_format_uint(va_list args, t_flags flags);
int		ft_format_lowhex(va_list args, t_flags flags);
int		ft_format_uphex(va_list args, t_flags flags);

void	ft_put_hex(unsigned int nb, char format);
int		ft_hexlen(unsigned int nb);

void	ft_put_ptr(unsigned long ptr);

size_t	ft_intlen(unsigned int nb);
char	*ft_uitoa(unsigned int nb);

t_flags	init_flags(void);
int		ft_is_flag(char c);
int		ft_pad_witdh(int width, int size, int zero);

int		ft_print_positive(t_flags flags, long value);

#endif