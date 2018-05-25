/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:30:35 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/29 20:30:37 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *d;

	d = dest;
	if (len != 0)
	{
		while (len > 0 && *src != '\0')
		{
			*d++ = *src++;
			len--;
		}
		while (len > 0)
		{
			*d++ = '\0';
			len--;
		}
	}
	return (dest);
}
