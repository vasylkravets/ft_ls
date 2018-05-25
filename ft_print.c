/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:27:17 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/06 19:27:19 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		c_t(unsigned int nb)
{
	if (nb > 9)
	{
		return (c_t(nb / 10) + 1);
	}
	else
		return (1);
}

void	ft_info_length(t_fl *files, int info[14])
{
	while (files)
	{
		info[1] = c_t(files->st.st_nlink);
		(info[0] < info[1]) ? info[0] = info[1] : info[1];
		if (getpwuid(files->st.st_uid))
			info[3] = ft_strlen(getpwuid(files->st.st_uid)->pw_name);
		else
			info[3] = ft_strlen(ft_itoa(files->st.st_uid));
		(info[2] < info[3]) ? info[2] = info[3] : info[2];
		if (getgrgid(files->st.st_gid))
			info[5] = ft_strlen(getgrgid(files->st.st_gid)->gr_name);
		else
			info[5] = ft_strlen(ft_itoa(files->st.st_gid));
		(info[4] < info[5]) ? info[4] = info[5] : info[4];
		info[7] = c_t(files->st.st_size);
		(info[6] < info[7]) ? info[6] = info[7] : info[6];
		info[9] = c_t(files->st.st_rdev);
		(info[8] < info[9]) ? info[8] = info[9] : info[8];
		info[11] = c_t(files->st.st_rdev & 0xFFFFFF);
		(info[10] < info[11]) ? info[10] = info[11] : info[10];
		info[13] = c_t(files->st.st_rdev >> 24);
		(info[12] < info[13]) ? info[12] = info[13] : info[12];
		files = files->next;
	}
}

void	ft_sub_print_dir(t_fl *files, t_fl *fl, int info[14])
{
	t_fl *temp;

	temp = NULL;
	while (files)
	{
		if (S_ISDIR(files->st.st_mode))
		{
			if (temp && fl->count_two == 1)
				ft_printf("\n");
			fl->count_two = 1;
			if (fl->size_lst > 1 || fl->test == 1)
				ft_printf("%s:\n", files->dir);
			print_all(NULL, files, fl, info);
		}
		temp = files;
		files = files->next;
	}
}

void	ft_sub_print_dir_two(t_fl *files, t_fl *fl, int info[14])
{
	fl->count_one++;
	if (!S_ISDIR(files->st.st_mode))
	{
		if (fl->l == 0)
		{
			fl->count_two++;
			ft_printf("%s\n", files->dir);
		}
		else
			ft_flag_l(files, info, NULL);
	}
}

void	ft_print_dir(t_fl *files, t_fl *fl, int info[14])
{
	t_fl *temp;
	t_fl *temp2;

	temp = NULL;
	temp2 = files;
	if (files == NULL)
		return ;
	ft_info_length(files, info);
	while (files)
	{
		ft_sub_print_dir_two(files, fl, info);
		files = files->next;
	}
	if (fl->l == 0 && !files)
	{
		if ((fl->count_one - fl->count_two != 0) && (fl->count_two != 0))
			ft_printf("\n");
	}
	files = temp2;
	fl->count_two = 0;
	ft_sub_print_dir(files, fl, info);
	free(temp2->dir);
}
