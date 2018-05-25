/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:59:03 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/01 18:59:05 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned long long	nt;
	int					neg;

	neg = 0;
	n = 0;
	while (*str == '\n' || *str == '\t' || *str == '\r' ||\
		*str == '\f' || *str == ' ' || *str == '\v')
		str++;
	(*str == '-') ? neg = -1 : 0;
	(*str == '+') ? neg = 1 : 0;
	(neg != 0) ? str++ : str;
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		nt = (n * 10) + (*str - 48);
		n = (n * 10) + (*str - 48);
		str++;
	}
	if ((n > 9223372036854775807 && neg == -1) || (nt > n && neg == -1))
		return (0);
	if ((n >= 9223372036854775807 && neg == 1) || (nt > n && neg == 1))
		return (-1);
	if (neg != 0)
		return (neg * n);
	return ((int)n);
}
