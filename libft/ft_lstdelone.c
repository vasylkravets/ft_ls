/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:58 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/16 11:40:00 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*next;

	if (alst && del && *alst)
	{
		next = ((*alst)->next);
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = next;
	}
}
