/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:58:34 by luciehdr          #+#    #+#             */
/*   Updated: 2020/11/23 15:59:37 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;
	size_t	size;
	size_t	size_total;

	if (!s)
		return (NULL);
	copy = NULL;
	i = 0;
	size = ft_strlen(s);
	size_total = (len >= size - start) ? size - start : len;
	if (!(copy = malloc(sizeof(char) * (size_total + 1))))
		return (NULL);
	while (s[start + i] && i < len && size > start)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
