/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cpec_su.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:49:02 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 13:49:04 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_main_for_su_only_count(int count, unsigned int i, t_flags *flag)
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
}

void	ft_count_bit_int_row(unsigned int *spec_su, t_flags *flag)
{
	int temp;
	int i;
	int j;

	i = 0;
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
		ft_main_for_su_only_count(j, temp, flag);
		i++;
	}
}

int		ft_check_cpec_su(va_list *ap, t_flags *flag)
{
	unsigned int	*spec_su;

	spec_su = va_arg(*ap, unsigned int*);
	if (spec_su == NULL)
	{
		write(1, "(null)", 6);
		flag->value_for_return += 6;
		return (0);
	}
	ft_count_bit_int_row(spec_su, flag);
	flag->reserv = flag->count_bit;
	flag->count_bit = 0;
	ft_print_cpec_su(spec_su, flag);
	return (0);
}
