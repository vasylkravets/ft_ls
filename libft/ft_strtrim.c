/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:10:12 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/07 22:10:13 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	len_for_malloc(char *s)
{
	size_t	len_space;
	size_t	len_string;
	size_t	sum;
	size_t	size;

	size = 0;
	len_string = ft_strlen(s);
	while (s[size] == '\n' || s[size] == '\t' || s[size] == ' ')
	{
		size++;
	}
	len_space = size;
	if (s[size] != '\0')
	{
		size = len_string - 1;
		while (s[size] == '\n' || s[size] == '\t' || s[size] == ' ')
		{
			size--;
			len_space++;
		}
	}
	sum = len_string - len_space;
	return (sum);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;
	size_t	len_string;
	size_t	b;

	if (s == NULL)
		return (NULL);
	len_string = len_for_malloc((char*)s);
	str = (char*)malloc(sizeof(char) * (len_string + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	b = 0;
	while (b < len_string)
	{
		str[b] = s[i];
		i++;
		b++;
	}
	str[b] = '\0';
	return (str);
}
