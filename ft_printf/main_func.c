/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:33:37 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 10:33:39 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_reset(t_flags *flag)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->val_wid = -1;
	flag->val_pr = -1;
	flag->md = '\0';
	flag->specifier = '\0';
	flag->sig = '\0';
	flag->interest = '\0';
	flag->count_bit = 0;
	flag->null = 0;
}

int		ft_main_string(char *str, va_list *ap, t_flags *flag)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_reset(flag);
		if (str[i] == '%' && str[i])
		{
			i++;
			while (!SPEC(str[i]) && str[i])
			{
				ft_check_flag(str, flag, &i);
				ft_check_wid(str, flag, &i, ap);
				ft_check_modifiers(str, flag, &i);
				if (INVALID(str[i]))
					break ;
			}
			ft_check_specifier(str, flag, &i);
			ft_kind_specifier(ap, flag);
		}
		else
			flag->value_for_return += fft_putchar(str[i++]);
	}
	return (flag->value_for_return);
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		value;
	t_flags	*flag;

	va_start(ap, fmt);
	flag = (t_flags *)malloc(sizeof(t_flags));
	flag->value_for_return = 0;
	value = ft_main_string(fmt, &ap, flag);
	va_end(ap);
	free(flag);
	return (value);
}
