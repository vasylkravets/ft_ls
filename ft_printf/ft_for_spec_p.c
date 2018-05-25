/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:53:07 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 17:53:09 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_subfunc_for_p(char *s, t_flags *flag, int len)
{
	char *s_new;

	s_new = ft_strnew(flag->val_wid - len);
	if (flag->minus == 1)
		s = ft_strjoin(s, ft_memset(s_new, ' ', flag->val_wid - len));
	else if (flag->zero == 1)
		s = ft_strjoin(ft_memset(s_new, '0', flag->val_wid - len), s);
	else
		s = ft_strjoin(ft_memset(s_new, ' ', flag->val_wid - len), s);
	return (s);
}

void		ft_format_acord_flags_for_unsigned_spec_p(char *s, t_flags *flag)
{
	char	*s_new;
	int		i;
	int		len;

	i = 0;
	if (flag->val_pr > (len = ft_strlen(s)) && s[2] != '0')
	{
		s_new = ft_strnew(flag->val_pr - len + 2);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr
			- len + 4)), s = ft_strsub(s, 2, len));
		s[1] = 'x';
	}
	else if (flag->val_pr > (len = ft_strlen(s)))
	{
		s_new = ft_strnew(flag->val_pr - 1);
		s = ft_strjoin(s, ft_memset(s_new, '0', (flag->val_pr - 1)));
	}
	if (flag->val_wid > (len = ft_strlen(s)))
		s = ft_subfunc_for_p(s, flag, len);
	(flag->minus || (s[1] != ' ' && ft_isdigit(s[2])
		&& ft_isdigit(s[0]))) ? s[1] = 'x' : s[1];
	len = ft_strlen(s);
	ft_putstr(s);
	flag->value_for_return = flag->value_for_return + len;
}

uint64_t	ft_rec(int base, int i)
{
	if (i == 0)
		return (1);
	else
		return (base * ft_rec(base, i - 1));
}

char		*ft_itoa_base_for_p(uint64_t value, int base, char c, t_flags *flag)
{
	unsigned long	i;
	char			*str;

	(flag->val_pr == 0) ? (i = 0)
	: (i = 1);
	while (ft_rec(base, i) - 1 < value)
		i++;
	str = ft_strnew(i += 2);
	while (i-- > 0)
	{
		str[i] = (value % base) + (value % base > 9 ? c - 10 : '0');
		value = value / base;
	}
	if ((flag->val_wid > 0) && flag->zero)
		((str[0] = '0')
			&& (str[1] = '0'));
	else if (ft_strlen(str) > 2)
		((str[0] = '0')
			&& (str[1] = 'x'));
	else if (ft_strlen(str) == 2)
		((str[0] = '0')
			&& (str[1] = 'x'));
	return (str);
}

void		ft_for_spec_p(va_list *ap, t_flags *flag)
{
	uint64_t	spec_p;
	uint64_t	spec_ret;
	char		*s;

	spec_p = (uint64_t)va_arg(*ap, void*);
	spec_ret = ft_check_and_ret_value_u(flag, spec_p);
	s = ft_itoa_base_for_p(spec_p, 16, 'a', flag);
	ft_format_acord_flags_for_unsigned_spec_p(s, flag);
	ft_strdel(&s);
}
