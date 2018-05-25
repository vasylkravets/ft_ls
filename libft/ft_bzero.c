/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:30:45 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/27 15:30:49 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t length)
{
	size_t			i;
	unsigned char	*dest1;

	dest1 = dest;
	i = 0;
	while (i < length)
	{
		dest1[i] = 0;
		i++;
	}
}
