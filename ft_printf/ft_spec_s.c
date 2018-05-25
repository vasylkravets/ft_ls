/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:52:16 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 14:52:19 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_help(int *in, char *s, t_flags *flag, int *len)
{
	char	*s_new;

	*in = 2;
	*len = flag->val_wid - *len;
	s_new = ft_strnew(*len + 1);
	if (flag->minus == 1)
		s = ft_strjoin(s, ft_memset(s_new, ' ', *len));
	else if (flag->zero == 1)
		s = ft_strjoin(ft_memset(s_new, '0', *len), s);
	else
		s = ft_strjoin(ft_memset(s_new, ' ', *len), s);
	*len = ft_strlen(s);
	ft_strdel(&s_new);
	return (s);
}

void	ft_sub_funk_for_spec_s(char *s, t_flags *flag, int *i)
{
	int		len;
	char	*temp;
	int		in;

	in = 0;
	temp = NULL;
	(s == NULL) ? flag->null = 1 : flag->null;
	(s == NULL) ? s = ft_strdup("(null)") : s;
	len = ft_strlen(s);
	if (flag->val_pr >= 0)
		if (flag->val_pr < (len = ft_strlen(s)))
		{
			s = ft_strsub(s, 0, flag->val_pr);
			temp = s;
		}
	if ((flag->val_wid > (len = ft_strlen(s))))
		s = ft_help(&in, s, flag, &len);
	ft_strdel(&temp);
	write(1, &s[(*i)++], len)
	&& (flag->value_for_return = flag->value_for_return + len);
	(flag->null == 1 || in == 2) ? ft_strdel(&s) : (flag->null = -1);
}

void	ft_for_cpec_s(va_list *ap, t_flags *flag)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(*ap, char *);
	ft_sub_funk_for_spec_s(s, flag, &i);
}
