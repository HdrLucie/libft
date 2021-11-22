/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:32:20 by luciehdr          #+#    #+#             */
/*   Updated: 2020/12/01 19:38:16 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_double_tab(char **tab, int number_tab)
{
	while (number_tab >= 0)
	{
		free(tab[number_tab]);
		tab[number_tab] = NULL;
		number_tab--;
	}
	free(tab);
	tab = NULL;
}

static int	ft_counter_words(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	**ft_len_words(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i++] != c)
				size++;
			if (!(tab[j++] = malloc(sizeof(char) * (size + 1))))
			{
				ft_free_double_tab(tab, j);
				return (NULL);
			}
			size = 0;
		}
	}
	tab[j] = NULL;
	return (tab);
}

static char	**ft_fill_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				tab[k][j] = s[i];
				i++;
				j++;
			}
			tab[k][j] = '\0';
			k++;
			j = 0;
		}
	}
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = NULL;
	if (!(tab = malloc(sizeof(char *) * ft_counter_words(s, c) + 1)))
		return (NULL);
	ft_len_words(tab, s, c);
	ft_fill_tab(tab, s, c);
	return (tab);
}
