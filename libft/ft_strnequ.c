/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:46:37 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/07 17:46:39 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t size)
{
	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strncmp(s1, s2, size) == 0)
			return (1);
	}
	return (0);
}
