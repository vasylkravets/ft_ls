/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_xl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:25:20 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 17:25:21 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_subfunc_for_x_accord(char *s, t_flags *flag, int len, char x)
{
	char	*s_new;

	s_new = ft_strnew(flag->val_wid - len);
	if (flag->minus == 1)
		s = ft_strjoin(s, ft_memset(s_new, ' ', flag->val_wid - len));
	else if (flag->zero == 1)
	{
		s = ft_strjoin(ft_memset(s_new, '0', flag->val_wid - len), s);
		(flag->hash) ? (s[1] = x) : s[1];
	}
	else
		s = ft_strjoin(ft_memset(s_new, ' ', flag->val_wid - len), s);
	return (s);
}

void		ft_format_acord_fl_x(char *s, t_flags *flag, char x)
{
	char	*s_new;
	int		len;

	len = 0;
	if (flag->val_pr > (len = ft_strlen(s)) && flag->hash)
	{
		s_new = ft_strnew(flag->val_pr - len + 2);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len + 2)), s);
		(flag->hash) ? (s[1] = x) : s[1];
	}
	else if (flag->val_pr > (len = ft_strlen(s)))
	{
		s_new = ft_strnew(flag->val_pr - len);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len)), s);
	}
	(flag->val_pr == 0) ? s = "\0" : s;
	if (flag->val_wid > (len = ft_strlen(s)))
		s = ft_subfunc_for_x_accord(s, flag, len, x);
	len = ft_strlen(s);
	ft_putstr(s);
	flag->value_for_return = flag->value_for_return + len;
}

char		*ft_itoa_base_for_x(uint64_t value, char c, t_flags *flag, int i)
{
	char		*str;

	i = 1;
	if (flag->val_pr == 0 && value == 0)
		return (ft_strdup("\0"));
	while (ft_rec(16, i) - 1 < value)
		i++;
	((flag->hash == 1 && value > 0) ||
		(flag->zero && flag->val_wid > 0 && flag->hash)) ? (i += 2) : i;
	str = ft_strnew(i);
	while (i-- > 0)
	{
		str[i] = (value % 16) + (value % 16 > 9 ? c - 10 : '0');
		value = value / 16;
	}
	if (flag->hash && (flag->val_wid > 0) && flag->zero)
		((str[0] = '0')
			&& (str[1] = '0'));
	else if ((flag->hash && c == 'a' && ft_strlen(str) > 2) && flag->val_pr < 0)
		((str[0] = '0')
			&& (str[1] = 'x'));
	else if (flag->hash && c == 'A' && ft_strlen(str) > 2 && flag->val_pr < 0)
		((str[0] = '0')
			&& (str[1] = 'X'));
	return (str);
}

void		ft_for_spec_xl(va_list *ap, t_flags *flag)
{
	int			i;
	char		*s;
	uint64_t	spec_x;
	uint64_t	spec_ret;

	i = 0;
	spec_x = va_arg(*ap, unsigned long long);
	spec_ret = ft_check_and_ret_value_u(flag, spec_x);
	s = ft_itoa_base_for_x(spec_ret, 'A', flag, i);
	ft_format_acord_fl_x(s, flag, 'X');
	ft_strdel(&s);
}
