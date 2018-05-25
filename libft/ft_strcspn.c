/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:24:38 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/17 19:24:40 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *string, const char *substring)
{
	size_t	retsize;
	char	*t;

	retsize = 0;
	while (*string != '\0')
	{
		t = (char*)substring;
		while (*t != '\0')
		{
			if (*string == *t)
				return (retsize);
			t++;
		}
		if (*t == '\0')
		{
			retsize++;
		}
		string++;
	}
	return (retsize);
}
