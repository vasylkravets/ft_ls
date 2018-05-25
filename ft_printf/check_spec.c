/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:19:50 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 13:19:52 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_funk_for_red(char *str, t_flags *flag, int *i)
{
	char	*s_new;
	char	s[2];
	int		j;
	int		len;

	len = 0;
	s[0] = str[*i];
	if ((flag->val_wid > 0))
	{
		s_new = ft_strnew(flag->val_wid - 1);
		if (flag->minus == 1)
			s_new = ft_strjoin(s, ft_memset(s_new, ' ', flag->val_wid - 1));
		else if (flag->zero == 1)
			s_new = ft_strjoin(ft_memset(s_new, '0', flag->val_wid - 1), s);
		else
			s_new = ft_strjoin(ft_memset(s_new, ' ', flag->val_wid - 1), s);
		len = ft_strlen(s_new);
		j = 0;
		write(1, &s_new[j++], len);
		ft_strdel(&s_new);
		flag->value_for_return = flag->value_for_return + len;
		(*i)++;
	}
}

void	ft_check_specifier(char *str, t_flags *flag, int *i)
{
	if (SPEC(str[*i]))
	{
		flag->specifier = str[*i];
		(*i)++;
	}
	else if (!SPEC(str[*i]))
	{
		ft_funk_for_red(str, flag, i);
	}
}

void	ft_kind_specifier(va_list *ap, t_flags *flag)
{
	if (flag->specifier == 'S' ||
		(flag->specifier == 's' && flag->md == 'l'))
		ft_check_cpec_su(ap, flag);
	else if (flag->specifier == 's')
		ft_for_cpec_s(ap, flag);
	else if (flag->specifier == 'C' ||
		(flag->specifier == 'c' && flag->md == 'l'))
		ft_check_cpec_chu(ap, flag);
	else if (flag->specifier == 'c')
		ft_for_spec_c(ap, flag);
	(flag->specifier == 'd') ? ft_for_spec_d(ap, flag) : flag->specifier;
	(flag->specifier == 'D') ? ft_for_spec_dl(ap, flag) : flag->specifier;
	(flag->specifier == 'i') ? ft_for_spec_i(ap, flag) : flag->specifier;
	(flag->specifier == 'u') ? ft_for_spec_u(ap, flag) : flag->specifier;
	(flag->specifier == 'U') ? ft_for_spec_ul(ap, flag) : flag->specifier;
	(flag->specifier == 'x') ? ft_for_spec_x(ap, flag) : flag->specifier;
	(flag->specifier == 'X') ? ft_for_spec_xl(ap, flag) : flag->specifier;
	(flag->specifier == 'o') ? ft_for_spec_o(ap, flag) : flag->specifier;
	(flag->specifier == 'O') ? ft_for_spec_ol(ap, flag) : flag->specifier;
	(flag->specifier == 'p') ? ft_for_spec_p(ap, flag) : flag->specifier;
	(flag->specifier == '%') ? ft_check_interest(flag) : flag->specifier;
}
