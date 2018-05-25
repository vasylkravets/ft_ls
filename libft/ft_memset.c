/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:28:44 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/27 11:28:46 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t cnt)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	c1;

	dest1 = dest;
	c1 = c;
	i = 0;
	while (i < cnt)
	{
		dest1[i] = c1;
		i++;
	}
	return (dest1);
}
