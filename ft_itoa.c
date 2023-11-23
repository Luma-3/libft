/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:12:20 by jbrousse          #+#    #+#             */
/*   Updated: 2023/11/10 16:26:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nombre_int(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void	ft_putitoa(char *tab, int size, long nb, int index)
{
	while (index < size)
	{
		tab[size - 1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		index;
	long	nb;

	index = 0;
	size = ft_nombre_int(n);
	nb = n;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[index] = '-';
		nb = -nb;
		index++;
	}
	ft_putitoa(str, size, nb, index);
	str[size] = 0;
	return (str);
}
