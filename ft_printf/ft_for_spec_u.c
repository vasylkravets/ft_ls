/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:16:26 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 16:16:27 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_acord_flags_for_unsigned_spec(char *s, t_flags *flag)
{
	char	*s_new;
	int		i;
	int		len;

	if (flag->val_pr > (len = ft_strlen(s)))
	{
		s_new = ft_strnew(flag->val_pr - len);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len)), s);
	}
	(flag->val_pr == 0) ? s = "\0" : s;
	if (flag->val_wid > (len = ft_strlen(s)))
	{
		s_new = ft_strnew(flag->val_wid - len);
		if (flag->minus == 1)
			s = ft_strjoin(s, ft_memset(s_new, ' ', flag->val_wid - len));
		else if (flag->zero == 1)
			s = ft_strjoin(ft_memset(s_new, '0', flag->val_wid - len), s);
		else
			s = ft_strjoin(ft_memset(s_new, ' ', flag->val_wid - len), s);
	}
	i = 0;
	len = ft_strlen(s);
	write(1, &s[i++], len);
	flag->value_for_return = flag->value_for_return + len;
}

int		test_digit_for_unsitoa(unsigned long long int num)
{
	int digit;

	digit = 0;
	while (num > 0)
	{
		digit++;
		num = num / 10;
	}
	return (digit);
}

char	*ft_modif_itoa_for_unsign_spec(uint64_t n)
{
	char		*str;
	uint64_t	num;
	int			digit_count;

	if (n == 0)
		return (str = ft_strdup("0"));
	num = n;
	digit_count = 0;
	digit_count = test_digit_for_unsitoa(num);
	str = ft_strnew(digit_count);
	str[digit_count] = '\0';
	while (num > 0)
	{
		str[digit_count - 1] = num % 10 + '0';
		num = num / 10;
		digit_count--;
	}
	return (str);
}

void	ft_for_spec_u(va_list *ap, t_flags *flag)
{
	char		*s;
	uint64_t	spec_u;
	uint64_t	spec_ret;

	spec_u = va_arg(*ap, unsigned long long);
	spec_ret = ft_check_and_ret_value_u(flag, spec_u);
	s = ft_modif_itoa_for_unsign_spec(spec_ret);
	ft_format_acord_flags_for_unsigned_spec(s, flag);
	ft_strdel(&s);
}

void	ft_for_spec_ul(va_list *ap, t_flags *flag)
{
	flag->md = 'l';
	ft_for_spec_u(ap, flag);
}
