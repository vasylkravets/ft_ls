/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:47:52 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 15:46:04 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			test_digit_for_sitoa(size_t num)
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

char		*ft_subfunc_for_sitoa(long long int n, int digit_c, t_flags *flag)
{
	char	*str;
	size_t	num;

	if (n < 0 || flag->plus || flag->space)
	{
		if (n < 0)
		{
			n = -n;
			flag->sig = '-';
		}
		digit_c++;
	}
	num = n;
	digit_c = digit_c + test_digit_for_sitoa((size_t)num);
	str = ft_strnew(digit_c);
	while ((size_t)num > 0)
	{
		str[digit_c - 1] = num % 10 + '0';
		num = (size_t)num / 10;
		digit_c--;
	}
	if (digit_c == 1)
		str[0] = '0';
	return (str);
}

char		*ft_modif_itoa_for_sign_spec(intmax_t n, t_flags *flag)
{
	char	*str;
	int		digit_count;

	if (flag->val_pr == 0 && n == 0)
		return (str = ft_strdup("\0"));
	if (!flag->plus && !flag->space && n == 0)
		return (str = ft_strdup("0"));
	else if ((flag->plus || flag->space) && n == 0)
		return (str = ft_strdup("00"));
	digit_count = 0;
	str = ft_subfunc_for_sitoa(n, digit_count, flag);
	return (str);
}

intmax_t	ft_check_and_ret_value(t_flags *flag, intmax_t value)
{
	if (flag->md == 'H')
		value = (char)value;
	else if (flag->md == 'h')
		value = (short int)value;
	else if (flag->md == 'l')
		value = (long int)value;
	else if (flag->md == 'L')
		value = (long long int)value;
	else if (flag->md == 'j')
		value = (intmax_t)value;
	else if (flag->md == 'z')
		value = (size_t)value;
	else
		value = (int)value;
	return (value);
}

void		ft_for_spec_d(va_list *ap, t_flags *flag)
{
	char		*s;
	intmax_t	spec_d;
	intmax_t	spec_ret;

	spec_d = va_arg(*ap, long long int);
	spec_ret = ft_check_and_ret_value(flag, spec_d);
	s = ft_modif_itoa_for_sign_spec(spec_ret, flag);
	ft_format_acord_flags(s, flag);
}
