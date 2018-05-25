/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_spec_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:28:25 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 15:28:27 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_for_spec_c(va_list *ap, t_flags *flag)
{
	char	s[2];
	int		len;
	char	*s_new;
	int		i;

	len = 0;
	i = 0;
	s[0] = (char)va_arg(*ap, int);
	if (flag->val_wid > 1)
	{
		s_new = ft_strnew(flag->val_wid);
		(flag->zero == 1) ? ft_memset(s_new, '0', flag->val_wid)
		: ft_memset(s_new, ' ', flag->val_wid);
		if (flag->minus == 1)
			s_new[0] = s[0];
		else
			s_new[flag->val_wid - 1] = s[0];
		(s[0] == 0) ? (len = flag->val_wid)
		: (len = ft_strlen(s_new));
		write(1, &s_new[i++], len);
		ft_strdel(&s_new);
	}
	else
		write(1, &s[0], 1) && flag->value_for_return++;
	flag->value_for_return += len;
}
