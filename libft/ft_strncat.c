/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:07:37 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/30 14:07:40 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t len)
{
	char *ret;

	ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while ((len > 0) && ((*dest = *app) != '\0'))
	{
		dest++;
		app++;
		len--;
	}
	*dest = '\0';
	return (ret);
}
