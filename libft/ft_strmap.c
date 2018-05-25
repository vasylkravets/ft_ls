/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:39:56 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/06 21:39:57 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	size;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
