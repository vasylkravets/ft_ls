/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 22:29:30 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/25 23:32:33 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_sub_join(t_fl *file, t_fl *temp)
{
	char *t_char;
	char *name;

	t_char = ft_strjoin("/", file->dir);
	name = ft_strjoin(temp->dir, t_char);
	free(t_char);
	return (name);
}

void	ft_total(t_fl *files, t_fl *fl)
{
	int total;

	total = 0;
	if (fl->l == 1)
	{
		while (files)
		{
			total = total + files->st.st_blocks;
			files = files->next;
		}
		ft_printf("total %d\n", total);
	}
}

void	ft_recursion(t_fl *files, t_fl *one, t_fl *fl, int info[14])
{
	if (fl->rr == 1)
	{
		while (one)
		{
			if (!ft_strequ(one->dir, "..") && S_ISDIR(one->st.st_mode) &&
				!ft_strequ(one->dir, "."))
				print_all(files, one, fl, info);
			one = one->next;
		}
	}
}

int		ft_read_dir_sub(DIR *direct, char *pass)
{
	if (!direct)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(pass, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free(pass);
		return (1);
	}
	return (0);
}

void	print_all(t_fl *parent, t_fl *files, t_fl *fl, int info[14])
{
	t_fl *one;
	t_fl *temp_one;
	t_fl *temp_two;

	temp_two = files;
	one = ft_read_dir(parent, files, fl);
	if (!one)
		return ;
	ft_total(one, fl);
	ft_sort_data(one, fl);
	ft_bzero(info, sizeof(int) * 14);
	ft_info_length(one, info);
	temp_one = one;
	while (one)
	{
		if (fl->l == 0)
			ft_printf("%s\n", one->dir);
		else
			ft_flag_l(one, info, files);
		one = one->next;
	}
	one = temp_one;
	ft_recursion(files, one, fl, info);
	ft_lstdel_func(&temp_one);
}
