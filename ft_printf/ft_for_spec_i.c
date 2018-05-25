/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:14:02 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 16:14:03 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	ft_check_and_ret_value_u(t_flags *flag, uint64_t value)
{
	if (flag->md == 'H')
		value = (unsigned char)value;
	else if (flag->md == 'h')
		value = (unsigned short)value;
	else if (flag->md == 'l')
		value = (unsigned long)value;
	else if (flag->md == 'L')
		value = (unsigned long long)value;
	else if (flag->md == 'j')
		value = (uint64_t)value;
	else if (flag->md == 'z')
		value = (uint64_t)value;
	else
		value = (unsigned int)value;
	return (value);
}

void		ft_for_spec_dl(va_list *ap, t_flags *flag)
{
	flag->md = 'l';
	ft_for_spec_d(ap, flag);
}

void		ft_for_spec_i(va_list *ap, t_flags *flag)
{
	char			*s;
	long long int	spec_i;
	long long int	spec_ret;

	spec_i = va_arg(*ap, long long int);
	spec_ret = ft_check_and_ret_value(flag, spec_i);
	s = ft_modif_itoa_for_sign_spec(spec_ret, flag);
	ft_format_acord_flags(s, flag);
}
