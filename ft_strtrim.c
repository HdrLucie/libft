/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:58:29 by luciehdr          #+#    #+#             */
/*   Updated: 2020/11/23 21:48:47 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_in_str(char const *set, char const c)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	first_lap(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_is_in_str(set, s1[i]))
		i++;
	return (i);
}

static size_t	last_lap(char const *s1, char const *set, size_t i)
{
	size_t	j;

	j = ft_strlen(s1);
	if (j == 0)
		return (0);
	j--;
	while (ft_is_in_str(set, s1[j]) && j > i)
		j--;
	return (j);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1)
		return (NULL);
	i = first_lap(s1, set);
	j = last_lap(s1, set, i);
	k = 0;
	copy = NULL;
	if (!(copy = malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
	{
		copy[k] = s1[i];
		i++;
		k++;
	}
	copy[k] = '\0';
	return (copy);
}
