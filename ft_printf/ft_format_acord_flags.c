/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_acord_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:55:07 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 15:55:09 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sub_format_acord_flags(char *s, t_flags *flag, int len, char *s_new)
{
	char *temp;

	temp = s;
	s_new = ft_strnew(flag->val_wid - len);
	if (flag->minus == 1)
	{
		s = ft_strjoin(s, ft_memset(s_new, ' ', flag->val_wid - len));
		(flag->sig) ? ((s[0] = flag->sig)
			&& (flag->sig = '\0')) : s[0];
	}
	else if (flag->zero == 1 && flag->val_pr < 0)
	{
		s = ft_strjoin(ft_memset(s_new, '0', flag->val_wid - len), s);
		(flag->sig) ? (s[0] = flag->sig)
		&& (flag->sig = '\0') : s[0];
	}
	else
	{
		s = ft_strjoin(ft_memset(s_new, ' ', flag->val_wid - len), s);
		(flag->sig) ? ((s[flag->val_wid - len] = flag->sig) &&
			(flag->sig = '\0')) : s[0];
	}
	ft_strdel(&s_new);
	ft_strdel(&temp);
	return (s);
}

char	*ft_sub_format_acord(char *s, t_flags *flag, int len, char *s_new)
{
	char *temp;

	temp = s;
	if (flag->val_pr > (len = ft_strlen(s))
		&& (flag->space || flag->plus || flag->sig))
	{
		s_new = ft_strnew(flag->val_pr - len + 1);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len + 1)), s);
		ft_strdel(&temp);
	}
	else if (flag->val_pr > (len = ft_strlen(s)))
	{
		s_new = ft_strnew(flag->val_pr - len);
		ft_memset(s_new, '0', (flag->val_pr - len));
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len)), s);
		ft_strdel(&temp);
	}
	else if (flag->val_pr == (len = ft_strlen(s))
		&& (flag->space || flag->plus || flag->sig))
	{
		s_new = ft_strnew(flag->val_pr - len);
		s = ft_strjoin(ft_memset(s_new, '0', (flag->val_pr - len + 1)), s);
	}
	ft_strdel(&s_new);
	return (s);
}

void	ft_format_acord_flags(char *s, t_flags *flag)
{
	char	*s_new;
	int		i;
	int		len;

	s_new = NULL;
	len = 0;
	if (flag->val_pr >= (len = ft_strlen(s)))
	{
		s = ft_sub_format_acord(s, flag, len, s_new);
	}
	if (flag->val_wid > (len = ft_strlen(s)))
	{
		s = ft_sub_format_acord_flags(s, flag, len, s_new);
	}
	len = ft_strlen(s);
	(flag->sig) ? (s[0] = flag->sig) : s[0];
	i = 0;
	write(1, &s[i++], len);
	ft_strdel(&s);
	flag->value_for_return = flag->value_for_return + len;
}
