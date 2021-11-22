/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:53:47 by luciehdr          #+#    #+#             */
/*   Updated: 2020/11/30 21:01:54 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_wagon;
	t_list	*current_wagon;
	t_list	*model_wagon;

	if (!lst)
		return (NULL);
	if (!(head_wagon = ft_lstnew(f(lst->content))))
		return (NULL);
	current_wagon = head_wagon;
	model_wagon = lst->next;
	while (model_wagon)
	{
		if (!(current_wagon->next = ft_lstnew(f(model_wagon->content))))
		{
			ft_lstclear(&head_wagon, del);
			return (NULL);
		}
		current_wagon = current_wagon->next;
		model_wagon = model_wagon->next;
	}
	return (head_wagon);
}
