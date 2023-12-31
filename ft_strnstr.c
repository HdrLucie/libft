/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:58:05 by luciehdr          #+#    #+#             */
/*   Updated: 2020/11/23 15:32:50 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t len)
{
	size_t	i;

	i = 0;
	if (!aiguille && !meule_de_foin)
		return (NULL);
	if (ft_strlen(aiguille) == 0)
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] && i + ft_strlen(aiguille) <= len)
	{
		if (!(ft_strncmp(&meule_de_foin[i], aiguille, ft_strlen(aiguille))))
			return ((char*)&(meule_de_foin[i]));
		i++;
	}
	return (NULL);
}
