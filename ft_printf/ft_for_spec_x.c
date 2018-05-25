/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:28:19 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 16:28:20 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_for_spec_x(va_list *ap, t_flags *flag)
{
	int			i;
	char		*s;
	uint64_t	spec_x;
	uint64_t	spec_ret;

	i = 0;
	spec_x = va_arg(*ap, unsigned long long);
	spec_ret = ft_check_and_ret_value_u(flag, spec_x);
	s = ft_itoa_base_for_x(spec_ret, 'a', flag, i);
	ft_format_acord_fl_x(s, flag, 'x');
	ft_strdel(&s);
}
