/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:31:05 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 17:31:07 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_subfunc_for_o(char *s, t_flags *flag, int len)
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

void	ft_format_acord_flags_for_unsigned_spec_o(char *s, t_flags *flag)
{
	char	*s_new;
	int		len;

	if (flag->val_pr > (len = ft_strlen(s)))
	{
		s_new = ft_strnew(flag->val_pr - len);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len)), s);
	}
	else if (flag->val_pr == (len = ft_strlen(s))
		&& (flag->space || flag->plus))
	{
		s_new = ft_strnew(flag->val_pr - len + 1);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len + 1)), s);
	}
	if (flag->val_wid > (len = ft_strlen(s)))
		s = ft_subfunc_for_o(s, flag, len);
	len = ft_strlen(s);
	ft_putstr(s);
	flag->value_for_return = flag->value_for_return + len;
}

char	*ft_itoa_base_for_o(uint64_t value, int base, t_flags *flag)
{
	int			i;
	int			sign;
	char		*str;

	if (flag->val_pr == 0 && value == 0 && flag->hash)
		return (ft_strdup("0"));
	else if (flag->val_pr == 0 && value == 0)
		return (ft_strdup("\0"));
	else if (value == 0)
		return (ft_strdup("0"));
	i = 1;
	(flag->hash == 1) ? (sign = 1)
	: (sign = 0);
	while (ft_rec(base, i) - 1 < value)
		i++;
	str = ft_strnew(i + sign);
	while (i-- > 0)
	{
		str[i + sign] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (sign)
		str[0] = '0';
	return (str);
}

void	ft_for_spec_o(va_list *ap, t_flags *flag)
{
	char		*s;
	uint64_t	spec_o;
	uint64_t	spec_ret;

	spec_o = va_arg(*ap, unsigned long long);
	spec_ret = ft_check_and_ret_value_u(flag, spec_o);
	s = ft_itoa_base_for_o(spec_ret, 8, flag);
	ft_format_acord_flags_for_unsigned_spec_o(s, flag);
	ft_strdel(&s);
}

void	ft_for_spec_ol(va_list *ap, t_flags *flag)
{
	flag->md = 'l';
	ft_for_spec_o(ap, flag);
}
