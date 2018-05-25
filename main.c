/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:09:59 by vkravets          #+#    #+#             */
/*   Updated: 2018/03/30 13:20:19 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_change(t_fl *one, t_fl *two)
{
	char		*temp_dir;
	struct stat	temp_st;

	temp_dir = two->dir;
	temp_st = two->st;
	two->dir = one->dir;
	two->st = one->st;
	one->dir = temp_dir;
	one->st = temp_st;
}

void	ft_reset_flag(t_fl *fl)
{
	fl->l = 0;
	fl->rr = 0;
	fl->a = 0;
	fl->t = 0;
	fl->r = 0;
	fl->check = 0;
	fl->size_lst = 0;
	fl->count_one = 0;
	fl->count_two = 0;
	fl->double_sign = 0;
	fl->test = 0;
}

void	ft_sub_search_flag(char **argv, int *y, int *x, t_fl *fl)
{
	if (!ft_strchr("Rlrat1", argv[*y][*x]))
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(argv[*y][*x], 2);
		ft_putstr_fd("\nusage: ls [-Ralrt1] [file ...]\n", 2);
		exit(1);
	}
	(argv[*y][*x] == 'R') ? fl->rr = 1 : fl->rr;
	(argv[*y][*x] == 'l') ? fl->l = 1 : fl->l;
	(argv[*y][*x] == 'r') ? fl->r = 1 : fl->r;
	(argv[*y][*x] == 'a') ? fl->a = 1 : fl->a;
	(argv[*y][*x] == 't') ? fl->t = 1 : fl->t;
}

int		ft_search_flag(int argc, char **argv, t_fl *fl)
{
	int x;
	int y;

	y = 0;
	while (++y < argc && argv[y][0] == '-')
	{
		x = 0;
		if (argv[y][0] == '-' && !argv[y][1])
			return (y);
		while (argv[y][++x] != '\0' && !fl->double_sign)
		{
			if (argv[y][0] == '-' && argv[y][1] == '-' && !argv[y][2])
			{
				fl->double_sign++;
				return (y + 1);
			}
			ft_sub_search_flag(argv, &y, &x, fl);
		}
	}
	return (y);
}

int		main(int argc, char **argv)
{
	t_fl	*fl;
	t_fl	*files;
	int		info[14];
	int		count;

	fl = ft_memalloc(sizeof(t_fl));
	ft_reset_flag(fl);
	count = ft_search_flag(argc, argv, fl);
	files = ft_add_list(argc, argv, fl, count);
	ft_bzero(info, sizeof(int) * 14);
	ft_list_size(files, fl);
	ft_print_dir(files, fl, info);
	free(files);
	free(fl);
	return (0);
}
