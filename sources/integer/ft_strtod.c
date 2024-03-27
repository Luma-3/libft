/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:35:49 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/23 16:39:51 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_nb(const char *str, int *i)
{
	double	nb;
	double	div;

	nb = 0;
	div = 0.0;
	while (str[*i] && ((47 < str[*i] && str[*i] < 58) || str[*i] == '.'))
	{
		if (str[*i] == '.' && div < 0.0)
			return (-1);
		if (str[*i] == '.')
			div = 10;
		else
		{
			if (div > 0.0)
			{
				nb += (str[*i] - '0') / div;
				div *= 10;
			}
			else
				nb = nb * 10 + str[*i] - '0';
		}
		(*i)++;
	}
	return (nb);
}

double	ft_strtod(const char *str)
{
	double	nb;
	double	sign;
	int		i;

	i = 0;
	sign = 1;
	while ((8 < str[i] && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nb = get_nb(str, &i);
	return (nb * sign);
}
