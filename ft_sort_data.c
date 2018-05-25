/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:43:32 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/07 14:43:42 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		subfunc_for_sort_time(t_fl *lst1, t_fl *lst2, t_fl *fl)
{
	if (lst1->st.st_mtimespec.tv_sec == lst2->st.st_mtimespec.tv_sec)
	{
		if (lst1->st.st_mtimespec.tv_nsec == lst2->st.st_mtimespec.tv_nsec)
			return (ft_sort_final_alphabet(lst1, lst2, fl));
		if (fl->r == 1)
			return ((lst1->st.st_mtimespec.tv_nsec >
				lst2->st.st_mtimespec.tv_nsec) ? 1 : 0);
		else
			return ((lst1->st.st_mtimespec.tv_nsec <
				lst2->st.st_mtimespec.tv_nsec) ? 1 : 0);
	}
	if (fl->r == 1)
		return ((lst1->st.st_mtimespec.tv_sec >
			lst2->st.st_mtimespec.tv_sec) ? 1 : 0);
	else
		return ((lst1->st.st_mtimespec.tv_sec <
			lst2->st.st_mtimespec.tv_sec) ? 1 : 0);
}

void	ft_sort_time(t_fl *start, t_fl *fl)
{
	t_fl	*one;
	int		flag;

	if (!start)
		return ;
	flag = 1;
	while (flag)
	{
		one = start;
		flag = 0;
		while (one->next)
		{
			if (subfunc_for_sort_time(one, one->next, fl))
			{
				ft_change(one, one->next);
				flag = 1;
			}
			one = one->next;
		}
	}
}

int		ft_sort_final_alphabet(t_fl *lst1, t_fl *lst2, t_fl *fl)
{
	int i;

	i = (ft_strcmp(lst1->dir, lst2->dir));
	if (fl->r == 1)
	{
		if (i > 0)
			return (0);
		return (1);
	}
	else
	{
		if (i > 0)
			return (1);
		return (0);
	}
}

void	ft_sort_alphabet(t_fl *start, t_fl *fl)
{
	t_fl	*one;
	int		flag;

	if (!start)
		return ;
	flag = 1;
	while (flag)
	{
		one = start;
		flag = 0;
		while (one->next)
		{
			if (ft_sort_final_alphabet(one, one->next, fl))
			{
				ft_change(one, one->next);
				flag = 1;
			}
			one = one->next;
		}
	}
}

void	ft_sort_data(t_fl *files, t_fl *fl)
{
	if (fl->t == 1)
		ft_sort_time(files, fl);
	else
		ft_sort_alphabet(files, fl);
}
