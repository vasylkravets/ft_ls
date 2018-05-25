/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:41:59 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/27 21:42:01 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)source == (unsigned char)c)
		{
			*(unsigned char*)dest++ = *(unsigned char*)source++;
			return (dest);
		}
		*(unsigned char*)dest++ = *(unsigned char*)source++;
	}
	return (NULL);
}
