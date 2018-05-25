/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:01:53 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/08 18:01:55 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(const char *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static	void	ft_free(char ***ret, int nb)
{
	while (nb >= 0)
	{
		ft_memdel((void*)&(*ret[nb]));
		nb--;
	}
	free(*ret);
	*ret = NULL;
}

static char		*ft_word(const char *s, size_t i, char c)
{
	char	*word;
	size_t	wl;
	size_t	j;

	wl = word_len(s, i, c);
	j = 0;
	word = (char *)malloc(sizeof(char) * (wl + 1));
	if (!word)
		return (NULL);
	while (j < wl)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i[2];
	char	**ret;

	if (!s)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	if (!(ret = (char**)malloc(sizeof(char *) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (s[i[0]] != '\0')
	{
		(s[i[0]] == c) ? i[0]++ : i[0];
		if (s[i[0]] && s[i[0]] != c)
		{
			ret[i[1]] = ft_word(s, i[0], c);
			if (!(ret[i[1]++]))
			{
				ft_free(&ret, i[1] - 1);
				return (NULL);
			}
			i[0] += (word_len(s, i[0], c));
		}
	}
	ret[i[1]] = NULL;
	return (ret);
}
