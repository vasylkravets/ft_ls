/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:53:00 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/07 14:53:01 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[size])
		size++;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	while (*s != '\0')
	{
		str[i] = (*f)(i, *s);
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
