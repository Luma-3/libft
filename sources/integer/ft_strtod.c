/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:35:49 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/21 13:37:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int(const char *str, int i)
{
	int	nb;

	nb = 0;
	while (str[i] && (47 < str[i] && str[i] < 58))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

static double	get_dec(const char *str, int i)
{
	double	nb;

	nb = 0;
	while (str[i] && (47 < str[i] && str[i] < 58))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb / 10);
}

double	ft_strtod(const char *str)
{
	double	nb;
	double	sign;
	int		i;

	i = 0;
	nb = 0;
	sign = 1;
	while ((8 < str[i] && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nb = (double)get_int(str, i);
	nb += get_dec(str, i);
	return (nb * sign);
}
