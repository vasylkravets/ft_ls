/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:19:37 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/10 19:19:39 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_root_file(t_fl *file)
{
	char temp[10];

	ft_memset(temp, '-', 9);
	(file->st.st_mode & S_IRUSR) ? temp[0] = 'r' : temp[0];
	(file->st.st_mode & S_IWUSR) ? temp[1] = 'w' : temp[1];
	if (file->st.st_mode & S_ISUID)
		(file->st.st_mode & S_IXUSR) ? temp[2] = 's' :
	(temp[2] = 'S');
	else
		(file->st.st_mode & S_IXUSR) ? temp[2] = 'x' : temp[2];
	(file->st.st_mode & S_IRGRP) ? temp[3] = 'r' : temp[3];
	(file->st.st_mode & S_IWGRP) ? temp[4] = 'w' : temp[4];
	if (file->st.st_mode & S_ISGID)
		(file->st.st_mode & S_IXGRP) ? temp[5] = 's' :
	(temp[5] = 'S');
	else
		(file->st.st_mode & S_IXGRP) ? temp[5] = 'x' : temp[5];
	(file->st.st_mode & S_IROTH) ? temp[6] = 'r' : temp[6];
	(file->st.st_mode & S_IWOTH) ? temp[7] = 'w' : temp[7];
	if (file->st.st_mode & S_ISVTX)
		(file->st.st_mode & S_IXUSR) ? temp[8] = 't'
	: (temp[8] = 'T');
	else
		(file->st.st_mode & S_IXOTH) ? temp[8] = 'x' : temp[8];
	write(1, &temp, 9);
}

void	ft_print_type_file(t_fl *file)
{
	if ((file->st.st_mode & S_IFMT) == (S_IFBLK))
		ft_printf("b");
	else if ((file->st.st_mode & S_IFMT) == (S_IFCHR))
		ft_printf("c");
	else if ((file->st.st_mode & S_IFMT) == (S_IFDIR))
		ft_printf("d");
	else if ((file->st.st_mode & S_IFMT) == (S_IFIFO))
		ft_printf("f");
	else if ((file->st.st_mode & S_IFMT) == (S_IFLNK))
		ft_printf("l");
	else if ((file->st.st_mode & S_IFMT) == (S_IFREG))
		ft_printf("-");
	else if ((file->st.st_mode & S_IFMT) == (S_IFSOCK))
		ft_printf("s");
}

void	ft_time(t_fl *file, t_fl *temp)
{
	char	*tmp;
	time_t	currtime;
	time_t	var_time;
	time_t	res;

	var_time = file->st.st_mtime;
	currtime = time(0);
	tmp = ctime(&file->st.st_mtime);
	res = currtime - var_time;
	if (res > SIX_MON)
		ft_printf(" %3.3s %2.2s %5.5s ", &tmp[4], &tmp[8], &tmp[19]);
	else if (res < -SIX_MON)
		ft_printf(" %3.3s %2.2s %6.6s ", &tmp[4], &tmp[8], &tmp[23]);
	else
		ft_printf(" %3.3s %2.2s %5.5s ", &tmp[4], &tmp[8], &tmp[11]);
	ft_print_name(file, temp);
}

void	ft_print_name(t_fl *file, t_fl *temp)
{
	int		val;
	char	*name;
	char	stat[1024];

	if ((file->st.st_mode & S_IFMT) == S_IFLNK)
	{
		if (temp)
			name = ft_sub_join(file, temp);
		else
			name = ft_strdup(file->dir);
		val = readlink(name, stat, 1024);
		{
			if (val < 0)
			{
				free(name);
				perror("readlink");
				exit(EX_IOERR);
			}
		}
		stat[val] = '\0';
		ft_printf("%s -> %s", file->dir, stat);
		free(name);
	}
	else
		ft_printf("%s", file->dir);
}

void	ft_flag_l(t_fl *file, int info[14], t_fl *temp)
{
	ft_print_type_file(file);
	ft_print_root_file(file);
	ft_putstr(listxattr(file->dir, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
	ft_printf("%*d ", info[0] + 1, file->st.st_nlink);
	if (ft_printf("%-*s ", info[2] + 1, getpwuid(file->st.st_uid)->pw_name))
		;
	else if (getpwuid(file->st.st_uid))
		ft_printf("%-*s ", info[2] + 1, ft_itoa(file->st.st_uid));
	if (ft_printf("%-*s", info[4], getgrgid(file->st.st_gid)->gr_name))
		;
	else if (getgrgid(file->st.st_gid))
		ft_printf("%-*s", info[4], ft_itoa(file->st.st_gid));
	if (((file->st.st_mode & S_IFMT) == S_IFBLK) ||
	((file->st.st_mode & S_IFMT) == S_IFCHR))
	{
		if ((file->st.st_mode & S_IFMT) == S_IFLNK)
			ft_printf("%*s", info[12] + 1, "");
		else
			ft_printf("%*d,", info[12] + 1, file->st.st_rdev >> 24);
		ft_printf("%*d", info[10] + 1, file->st.st_rdev & 0xFFFFFF);
	}
	else
		ft_printf("%*d", info[6] + 2, file->st.st_size);
	ft_time(file, temp);
	ft_printf("\n");
}
