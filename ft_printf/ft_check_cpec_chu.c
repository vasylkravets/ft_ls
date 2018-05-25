/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cpec_chu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:03:07 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 15:03:09 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_cpec_chu(char print[5], t_flags *flag)
{
	int		i;
	char	*s_new;

	i = 0;
	if (flag->val_wid > 1)
	{
		s_new = ft_strnew(flag->val_wid - flag->count_bit);
		(flag->zero == 1) ? ft_memset(s_new, '0', flag->val_wid - flag->
			count_bit) : ft_memset(s_new, ' ', flag->val_wid - flag->count_bit);
		if (flag->minus == 1)
		{
			while (print[i])
				write(1, &print[i++], 1);
			ft_putstr(s_new);
		}
		else
		{
			ft_putstr(s_new);
			while (print[i])
				write(1, &print[i++], 1);
		}
	}
	else
		while (i < flag->count_bit)
			write(1, &print[i++], 1);
}

void	ft_main_for_chu(int count, unsigned int i, t_flags *flag)
{
	char print[5];

	if (count <= 7)
	{
		print[0] = i;
		print[1] = '\0';
		flag->count_bit += 1;
	}
	else if (count <= 11)
	{
		ft_subfunc_for_11(print, i);
		flag->count_bit += 2;
	}
	else if (count <= 16)
	{
		ft_subfunc_for_16(print, i);
		flag->count_bit += 3;
	}
	else
	{
		ft_subfunc_for_else(print, i);
		flag->count_bit += 4;
	}
	ft_print_cpec_chu(print, flag);
	flag->value_for_return += flag->count_bit;
}

int		ft_check_cpec_chu(va_list *ap, t_flags *flag)
{
	wchar_t			spec_chu;
	unsigned int	i;
	int				count;

	count = 0;
	spec_chu = va_arg(*ap, unsigned int);
	i = spec_chu;
	if (MB_CUR_MAX == 1 && i < 255)
	{
		write(1, &i, 1);
		flag->count_bit += 1;
	}
	else if (MB_CUR_MAX == 1)
		return (-1);
	else
	{
		while (i)
		{
			i /= 2;
			count++;
		}
		i = spec_chu;
		ft_main_for_chu(count, i, flag);
	}
	return (0);
}
