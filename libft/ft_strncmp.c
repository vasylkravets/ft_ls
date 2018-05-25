/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:39:18 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/01 18:39:22 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *string1;
	unsigned char *string2;

	if (n == 0)
		return (0);
	string1 = ((unsigned char*)s1);
	string2 = ((unsigned char*)s2);
	while ((*string1 && *string2) && (*string1 == *string2) && (n-- > 0))
	{
		if (!n)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
