/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:32:06 by luciehdr          #+#    #+#             */
/*   Updated: 2020/11/21 17:25:33 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_white_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\f' || str[i] == '\v' || str[i] == '\r'))
		i++;
	return (i);
}

int				ft_atoi(char *nptr)
{
	int				i;
	long long int	res;
	int				negatif;

	i = ft_white_space(nptr);
	negatif = 1;
	res = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negatif = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res * negatif < INT_MIN || res * negatif > INT_MAX)
			return (negatif < 0 ? 0 : -1);
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * negatif);
}
