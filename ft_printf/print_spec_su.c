/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_su.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:17:28 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 14:17:30 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_funk_for_width(t_flags *flag)
{
	char	*s_new;
	int		i;

	s_new = NULL;
	if ((flag->val_wid > 0))
	{
		s_new = ft_strnew(flag->val_wid - flag->reserv);
		if (flag->zero == 1)
			ft_memset(s_new, '0', flag->val_wid - flag->reserv);
		else
			ft_memset(s_new, ' ', flag->val_wid - flag->reserv);
	}
	i = 0;
	write(1, &s_new[i++], flag->val_wid - flag->reserv);
	flag->value_for_return += flag->val_wid - flag->reserv;
}

void	ft_main_for_su_with_print(int cnt, unsigned int i, t_flags *flag, int d)
{
	char	print[5];

	if (cnt <= 7)
	{
		print[0] = i;
		print[1] = '\0';
		flag->count_bit += 1;
	}
	else if (cnt <= 11)
	{
		flag->count_bit += 2;
		ft_subfunc_for_11(print, i);
	}
	else if (cnt <= 16)
	{
		flag->count_bit += 3;
		ft_subfunc_for_16(print, i);
	}
	else
	{
		flag->count_bit += 4;
		ft_subfunc_for_else(print, i);
	}
	while (print[d])
		write(1, &print[d++], 1);
}

void	ft_subfunc_for_print(unsigned int *spec_su, t_flags *flag)
{
	int temp;
	int i;
	int j;
	int d;

	d = 0;
	i = 0;
	flag->count_bit = 0;
	while (spec_su[i])
	{
		j = 0;
		temp = spec_su[i];
		while (temp)
		{
			temp /= 2;
			j++;
		}
		temp = spec_su[i];
		ft_main_for_su_with_print(j, temp, flag, d);
		i++;
	}
}

void	ft_print_cpec_su(unsigned int *spec_su, t_flags *flag)
{
	if (flag->val_wid > 0 && flag->val_pr < 0 && flag->minus)
	{
		ft_subfunc_for_print(spec_su, flag);
		flag->value_for_return += flag->count_bit;
		ft_funk_for_width(flag);
	}
	else if (flag->val_wid > 0 && flag->val_pr < 0)
	{
		ft_funk_for_width(flag);
		ft_subfunc_for_print(spec_su, flag);
		flag->value_for_return += flag->count_bit;
	}
	else if (flag->val_wid < 0 && flag->val_pr < 0)
	{
		ft_subfunc_for_print(spec_su, flag);
		flag->value_for_return += flag->count_bit;
	}
}
