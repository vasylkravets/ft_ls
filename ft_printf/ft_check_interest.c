/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_interest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:14:54 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 18:14:56 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_interest(t_flags *flag)
{
	char	s[2];
	int		len;
	char	*s_new;
	int		j;

	j = 0;
	s[0] = '%';
	len = 0;
	flag->interest = '%';
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
		write(1, &s_new[j++], len);
	}
	else
		write(1, &s[0], 1) && flag->value_for_return++;
	flag->value_for_return += len;
}
