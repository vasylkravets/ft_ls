/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:29:12 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/26 14:29:13 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define ABS(a) ((a) * (((a) > 0) * 2 - 1))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define SIX_MON			15778500

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sysexits.h>

typedef struct	s_fl
{
	int			l;
	int			rr;
	int			a;
	int			t;
	int			r;
	int			check;
	char		*dir;
	struct stat	st;
	int			size_lst;
	int			count_one;
	int			count_two;
	int			double_sign;
	int			test;
	struct s_fl *next;
}				t_fl;

char			*ft_sub_join(t_fl *file, t_fl *temp);
void			ft_change(t_fl *one, t_fl *two);
int				ft_read_dir_sub(DIR *direct, char *pass);
t_fl			*ft_add_list(int argc, char **argv, t_fl *fl, int y);
t_fl			*sub_func_error(char **argv, t_fl *fl, int y);
void			ft_sort_error(t_fl *start, t_fl *fl);
void			ft_list_size(t_fl *lst, t_fl *fl);
int				ft_file(char *file);
void			ft_change(t_fl *one, t_fl *two);
void			print_all(t_fl *parent, t_fl *files, t_fl *fl, int info[14]);
void			ft_print_error(t_fl *tmp2, t_fl *fl);
void			ft_lstdel_func(t_fl **alst);
void			ft_error(char *str_error);
void			ft_print_name(t_fl *file, t_fl *temp);
void			ft_free_lst(t_fl *alst);
t_fl			*new_list(t_fl *lst);
void			ft_info_length(t_fl *files, int info[14]);
void			ft_flag_l(t_fl *file, int info[14], t_fl *temp);
void			ft_sort_alphabet(t_fl *begin_list, t_fl *fl);
void			ft_sort_time(t_fl *files, t_fl *fl);
void			lst_back(t_fl **lst, t_fl *new);
t_fl			*ft_read_dir(t_fl *files, t_fl *temp, t_fl *fl);
int				ft_sort_final_alphabet(t_fl *lst1, t_fl *lst2, t_fl *fl);
void			ft_sort_data(t_fl *files, t_fl *fl);
void			ft_print_dir(t_fl *files, t_fl *fl, int info[14]);

#endif
