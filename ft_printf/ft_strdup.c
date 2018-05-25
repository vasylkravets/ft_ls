/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:57:44 by vkravets          #+#    #+#             */
/*   Updated: 2017/10/29 17:57:46 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*s1;

	if (s != NULL)
		i = 0;
	size = ft_strlen(s);
	s1 = (char*)malloc(sizeof(char) * size + 1);
	if (s1 == NULL)
		return (NULL);
	while (i < size)
	{
		s1[i] = s[i];
		i++;
	}
	s1[size] = '\0';
	return (s1);
}
