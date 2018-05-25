/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 22:22:37 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/25 22:22:38 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fl	*sub_func_lst_add(char **argv, t_fl *fl, int y)
{
	t_fl	*tmp;

	tmp = ft_memalloc(sizeof(t_fl));
	fl->check += 1;
	tmp->dir = ft_strdup(argv[y]);
	if (fl->l == 1)
	{
		lstat(tmp->dir, &(tmp->st));
	}
	else
		stat(tmp->dir, &(tmp->st));
	return (tmp);
}

t_fl	*make_dir(int argc, char **argv, t_fl *fl, int y)
{
	t_fl	*error;
	t_fl	*files;
	t_fl	*tmp;
	t_fl	*tmp2;

	tmp2 = NULL;
	files = NULL;
	while (y < argc)
	{
		if (!ft_file(argv[y]))
		{
			error = sub_func_error(argv, fl, y);
			lst_back(&tmp2, new_list(error));
			ft_lstdel_func(&error);
		}
		else
		{
			tmp = sub_func_lst_add(argv, fl, y);
			lst_back(&files, new_list(tmp));
			ft_lstdel_func(&tmp);
		}
		y++;
	}
	ft_sort_error(tmp2, fl);
	return (files);
}

t_fl	*ft_add_list(int argc, char **argv, t_fl *fl, int y)
{
	t_fl *files;
	t_fl *tmp;

	files = make_dir(argc, argv, fl, y);
	ft_list_size(files, fl);
	if (fl->check == 0 && fl->size_lst == 0)
	{
		tmp = ft_memalloc(sizeof(t_fl));
		tmp->dir = ft_strdup(".");
		lstat(tmp->dir, &(tmp->st));
		lst_back(&files, new_list(tmp));
		ft_lstdel_func(&tmp);
	}
	else
		ft_sort_data(files, fl);
	return (files);
}
