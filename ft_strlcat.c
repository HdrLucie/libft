/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:53:59 by luciehdr          #+#    #+#             */
/*   Updated: 2020/11/16 17:54:01 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t src_len;

	i = ft_strlen(dest);
	j = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < i)
		return (src_len + size);
	while (src[j] && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (src_len + i);
}
