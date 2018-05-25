/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:39:25 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/03 17:39:26 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char*)malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (size--)
	{
		ptr[i] = '\0';
		i++;
	}
	ptr[i] = '\0';
	if (!ptr)
		return (NULL);
	return (ptr);
}
