/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:58:02 by luciehdr          #+#    #+#             */
/*   Updated: 2020/10/30 16:14:01 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = NULL;
	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2)) + 1))))
		return (NULL);
	while (s1[j] != '\0')
	{
		dest[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (dest);
}
