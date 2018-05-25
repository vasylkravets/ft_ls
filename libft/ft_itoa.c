/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:01:53 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/08 18:01:55 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		test_digit(int num)
{
	int digit_count;

	digit_count = 0;
	while (num > 0)
	{
		digit_count++;
		num = num / 10;
	}
	return (digit_count);
}

static	char	*ft_f(int num, int digit_count)
{
	char	*str;

	if (num < 0)
	{
		num = -num;
		digit_count++;
	}
	digit_count = digit_count + test_digit(num);
	if ((str = (char*)malloc(sizeof(char) * (digit_count + 1))) == NULL)
		return (NULL);
	str[digit_count] = '\0';
	while (num > 0)
	{
		str[digit_count - 1] = num % 10 + '0';
		num = num / 10;
		digit_count--;
	}
	if (digit_count == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int num)
{
	char	*str;
	int		digit_count;

	digit_count = 0;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (num == 0)
		return (ft_strdup("0"));
	else
		str = ft_f(num, digit_count);
	return (str);
}
