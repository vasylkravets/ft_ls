/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:47:21 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/31 14:47:23 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big1, const char *little1, size_t len)
{
	size_t		k;
	const char	*big;
	const char	*little;

	if (*little1 == '\0')
		return ((char *)big1);
	k = ft_strlen(little1);
	while (*big1 != '\0' && len >= k)
	{
		little = little1;
		big = big1;
		while (*little != '\0' && *little == *big)
		{
			little++;
			big++;
		}
		if (*little == '\0')
			return ((char*)big1);
		big1++;
		len--;
	}
	return (0);
}
