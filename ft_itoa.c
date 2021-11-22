/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:54:11 by luciehdr          #+#    #+#             */
/*   Updated: 2020/12/01 19:44:55 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str);
	j--;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

static int	counter_number(int nb)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	nbr = nb;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	str = NULL;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (counter_number(n) + 1))))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	nb = n < 0 ? n * -1 : n;
	while (nb > 0)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
