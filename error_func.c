/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 22:12:33 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/25 22:12:35 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fl	*sub_func_error(char **argv, t_fl *fl, int y)
{
	t_fl	*error;

	fl->check += 1;
	error = ft_memalloc(sizeof(t_fl));
	error->dir = ft_strdup(argv[y]);
	return (error);
}

void	ft_error(char *str)
{
	ft_putstr_fd("ls", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_print_error(t_fl *tmp2, t_fl *fl)
{
	t_fl	*error;

	error = tmp2;
	while (tmp2)
	{
		ft_error(tmp2->dir);
		tmp2 = tmp2->next;
		fl->test = 1;
	}
	ft_lstdel_func(&error);
}

int		ft_sort_error_sub(t_fl *lst1, t_fl *lst2)
{
	int i;

	i = (ft_strcmp(lst1->dir, lst2->dir));
	if (i > 0)
		return (1);
	return (0);
}

void	ft_sort_error(t_fl *start, t_fl *fl)
{
	t_fl	*left;
	int		flag;
	char	*temp_dir;

	if (!start)
		return ;
	flag = 1;
	while (flag)
	{
		left = start;
		flag = 0;
		while (left->next)
		{
			if (ft_sort_error_sub(left, left->next))
			{
				temp_dir = left->next->dir;
				left->next->dir = left->dir;
				left->dir = temp_dir;
				flag = 1;
			}
			left = left->next;
		}
	}
	ft_print_error(start, fl);
}
