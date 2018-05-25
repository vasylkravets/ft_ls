/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:44:39 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/12 12:44:41 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_search_sign(t_flags *flag)
{
	if (!flag->sig || flag->plus)
	{
		if (flag->space && flag->sig != '-'
			&& flag->sig != '+')
			flag->sig = ' ';
		if (flag->plus && flag->sig != '-')
			flag->sig = '+';
	}
}

void	ft_check_flag(char *str, t_flags *flag, int *i)
{
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == ' '
		|| str[*i] == '0' || str[*i] == '#')
	{
		if (str[*i] == '-')
			flag->minus = 1;
		else if (str[*i] == '+')
			flag->plus = 1;
		else if (str[*i] == ' ')
			flag->space = 1;
		else if (str[*i] == '#')
			flag->hash = 1;
		else if (str[*i] == '0')
			flag->zero = 1;
		(*i)++;
		(flag->minus == 1) ? flag->zero = 0 : flag->zero;
		(flag->plus == 1) ? flag->space = 0 : flag->space;
		ft_search_sign(flag);
	}
}

void	sub_ft_check_wid(char *str, t_flags *flag, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9' && str[*i - 1] != '.')
	{
		flag->val_wid = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
}

void	ft_check_wid(char *str, t_flags *flag, int *i, va_list *ap)
{
	if (str[*i] == '*')
	{
		flag->val_wid = va_arg(*ap, int);
		(*i)++;
	}
	else
		sub_ft_check_wid(str, flag, i);
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
		{
			flag->val_pr = va_arg(*ap, int);
			(*i)++;
		}
		else
		{
			flag->val_pr = ft_atoi(&str[*i]);
			while (str[*i] >= '0' && str[*i] <= '9')
				(*i)++;
		}
	}
}

void	ft_check_modifiers(char *str, t_flags *flag, int *i)
{
	while (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'j' || str[*i] == 'z')
	{
		if ((str[*i] == 'h' && str[*i + 1] == 'h'))
		{
			(!flag->md) ? flag->md = 'H' : flag->md;
			(*i)++;
		}
		else if (str[*i] == 'h')
			(!flag->md || flag->md == 'H') ? flag->md = 'h' : flag->md;
		else if (str[*i] == 'l' && str[*i + 1] == 'l')
		{
			(flag->md != 'j' && flag->md != 'z') ? flag->md = 'L' : flag->md;
			(*i)++;
		}
		else if (str[*i] == 'l')
		{
			if (!flag->md || flag->md == 'h' || flag->md == 'H')
				flag->md = 'l';
		}
		else if (str[*i] == 'j')
			(flag->md != 'z') ? flag->md = 'j' : flag->md;
		else if (str[*i] == 'z')
			flag->md = 'z';
		(*i)++;
	}
}
