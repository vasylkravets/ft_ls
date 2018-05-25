/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:42:21 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/10 12:42:23 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*made_name_pass_sub(char *old_name, char *pass_n)
{
	char	*old_folder;
	char	*join;

	old_folder = ft_strjoin(old_name, pass_n);
	ft_strdel(&pass_n);
	join = ft_strjoin(old_folder, "/");
	free(old_folder);
	return (join);
}

t_fl	*made_name_pass(t_fl *old, t_fl *files)
{
	char	*old_name;
	char	*pass_n;
	char	*join;

	pass_n = ft_strdup(files->dir);
	if (old)
		old_name = ft_strdup(old->dir);
	if (old && (!ft_strequ(old_name, pass_n)))
		join = made_name_pass_sub(old_name, pass_n);
	else
	{
		join = ft_strjoin(pass_n, "/");
		ft_strdel(&pass_n);
	}
	if (old && !ft_strequ("./", join))
		ft_printf("\n%.*s:\n", (ft_strlen(join) - 1), join);
	free(files->dir);
	files->dir = ft_strdup(join);
	if (old)
		free(old_name);
	ft_strdel(&join);
	return (files);
}

t_fl	*ft_stat_dir(t_fl *files, struct dirent *direc)
{
	t_fl *two;
	char *temp_var;

	two = ft_memalloc(sizeof(t_fl));
	two->dir = ft_strdup(direc->d_name);
	temp_var = ft_strjoin(files->dir, direc->d_name);
	lstat(temp_var, &(two->st));
	free(temp_var);
	return (two);
}

t_fl	*ft_subfunc_read_dir(t_fl *files, DIR *direct, t_fl *fl)
{
	t_fl			*one;
	t_fl			*two;
	struct dirent	*direc;

	direc = readdir(direct);
	one = NULL;
	while (direc)
	{
		if (direc->d_name[0] != '.' || fl->a == 1)
		{
			two = ft_stat_dir(files, direc);
			lst_back(&one, new_list(two));
			ft_lstdel_func(&two);
		}
		direc = readdir(direct);
	}
	return (one);
}

t_fl	*ft_read_dir(t_fl *parent, t_fl *files, t_fl *fl)
{
	char	*pass;
	DIR		*direct;
	t_fl	*back;
	t_fl	*ret_files;

	back = NULL;
	ret_files = made_name_pass(parent, files);
	direct = opendir(ret_files->dir);
	pass = ft_strdup(files->dir);
	if (ft_read_dir_sub(direct, pass))
		return (NULL);
	back = ft_subfunc_read_dir(ret_files, direct, fl);
	closedir(direct);
	free(pass);
	return (back);
}
