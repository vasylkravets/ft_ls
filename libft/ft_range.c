/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:54:25 by vkravets          #+#    #+#             */
/*   Updated: 2017/11/17 18:54:26 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *d;
	int t;

	i = 0;
	t = max - min;
	if (min >= max)
		return (NULL);
	d = (int*)malloc(sizeof(int) * (max - min));
	if (!d)
		return (NULL);
	while (i < t)
	{
		d[i] = min;
		i++;
		++min;
	}
	return (d);
}
