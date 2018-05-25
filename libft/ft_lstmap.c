/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:26:01 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/17 21:26:04 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	element = (t_list*)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element = f(lst);
	head = element;
	lst = lst->next;
	while (lst != NULL)
	{
		element->next = f(lst);
		if (!element->next)
		{
			free(element->next);
			return (NULL);
		}
		element = element->next;
		lst = lst->next;
	}
	element->next = NULL;
	return (head);
}
