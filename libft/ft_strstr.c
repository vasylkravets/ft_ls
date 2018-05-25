/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:01:35 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/30 22:01:36 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	char	*l;
	char	*begin;

	if (!*little)
		return ((char*)big);
	b = (char*)big;
	while (*b)
	{
		begin = b;
		l = (char*)little;
		while (*b && *l && *b == *l)
		{
			b++;
			l++;
		}
		if (!*l)
			return (begin);
		b = (begin + 1);
	}
	return (NULL);
}
