/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 22:06:13 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/25 22:06:15 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstdel_func(t_fl **alst)
{
	t_fl *tmp;
	t_fl *tmp_next;

	tmp = *alst;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->dir);
		free(tmp);
		tmp = tmp_next;
	}
	*alst = NULL;
}

t_fl	*new_list(t_fl *lst)
{
	t_fl *new;

	new = ft_memalloc(sizeof(t_fl));
	new->next = NULL;
	new->dir = ft_strdup(lst->dir);
	new->st = lst->st;
	return (new);
}

void	lst_back(t_fl **alst, t_fl *new)
{
	t_fl	*tmp;

	tmp = *alst;
	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_list_size(t_fl *lst, t_fl *fl)
{
	t_fl	*tlst;
	int		i;

	i = 0;
	tlst = lst;
	while (tlst)
	{
		i++;
		tlst = tlst->next;
	}
	fl->size_lst = i;
}

int		ft_file(char *file)
{
	struct stat		buffer;

	if (lstat(file, &buffer) == 0)
		return (1);
	return (0);
}
