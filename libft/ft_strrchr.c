/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:56:13 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/30 20:56:14 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;
	char		c1;

	c1 = c;
	ret = s;
	while (*s++)
		;
	while (--s != ret && *s != c1)
		;
	if (*s == c1)
		return ((char*)s);
	return (NULL);
}
