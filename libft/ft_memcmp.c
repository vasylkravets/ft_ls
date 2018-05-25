/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:05:21 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/28 20:05:24 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src, const void *dest, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*dest1;
	int					res;

	src1 = src;
	dest1 = dest;
	while (n--)
	{
		res = *src1++ - *dest1++;
		if (res != 0)
			return (res);
	}
	return (0);
}
