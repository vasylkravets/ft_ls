/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:41:34 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/28 13:41:36 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = dest;
	src1 = src;
	i = 0;
	if (dest1 <= src1)
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	else
	{
		i = n + 1;
		while (--i > 0)
			dest1[i - 1] = src1[i - 1];
	}
	return (dest1);
}
